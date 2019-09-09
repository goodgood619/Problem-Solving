#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int n;
string ans[1001];
int main(){
	scanf("%d", &n);
	ans[1] = "SK";
	ans[2] = "CY";
	ans[3] = "SK";
	ans[4] = "SK";
	for (int i = 5; i <= n; i++) {
		if (ans[i - 1] == "CY" || ans[i - 3] == "CY" || ans[i - 4] == "CY") {
			ans[i] = "SK";
		}
		else ans[i] = "CY";
	}
	cout << ans[n] << endl;
	return 0;
}