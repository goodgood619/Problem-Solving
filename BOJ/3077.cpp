#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
int n;
string ans[2505];
string s[2505];
map<string, int> m;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		m[ans[i]] = i+1;
	}
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ok = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++){
			int first = m[s[i]];
			int second = m[s[j]];
			if (first < second) ok++;
			else continue;
		}
	}
	printf("%d/%d\n", ok,n*(n-1)/2);
	return 0;
}