#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int check[30];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int length = s.size();
		if (s[length - 1] == '0' || s[length - 1] == '2' || s[length - 1] == '4' || s[length - 1] == '6' || s[length - 1] == '8')  printf("even\n");
		else printf("odd\n");
	}
	return 0;
}