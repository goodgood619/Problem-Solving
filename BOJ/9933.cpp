#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <map>
using namespace std;
string s[105];
string ans;
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	bool check = false;
	for (int i = 0; i < n; i++) {
		string password = s[i];
		string repass = password;
		reverse(repass.begin(), repass.end());
		for (int j = 0; j < n; j++) {
			if (repass != s[j]) continue;
			else {
				ans = password;
				check = true;
				break;
			}
		}
		if (check) break;
	}
	printf("%d %c\n", ans.size(), ans[ans.size() / 2]);
	return 0;
}