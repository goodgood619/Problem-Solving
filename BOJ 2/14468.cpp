#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int check[30];
int main(){
	string s;
	cin >> s;
	int length = s.size();
	int ans = 0;
	for (int i = 0; i < length; i++) {
		char here = s[i];
		int idx = -1;
		memset(check, 0, sizeof(check));
		for (int j = i; j < length; j++) {
			if (i == j) continue;
			else if (here == s[j]) {
				idx = j;
				break;
			}
		}
		for (int k = i; k <=idx; k++){
			check[s[k] - 'A']++;
		}
		if (idx != -1) {
			for (int k = 0; k < 26; k++) {
				if (check[k] == 1) ans++;
				else continue;
			}
		}
	}
	printf("%d\n", ans/2);
	return 0;
}