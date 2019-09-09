#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int n;
int main(){
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		printf("%d. %s\n", i, s.c_str());
	}
	return 0;
}