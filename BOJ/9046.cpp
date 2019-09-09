#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
int t;
int check[27];
map <int, int> m;
int main(){
	scanf("%d ", &t);
	while (t--) {
		memset(check, 0, sizeof(check));
		string s;
		getline(cin, s);
		int length = s.size();
		for (int i = 0; i < length; i++) {
			char c = s[i];
			if (c == ' ') continue;
			else check[s[i] - 96]++;
		}
		int Max = 0;
		int cnt = 0;
		for (int i = 1; i <= 26; i++) {
			Max = max(check[i], Max);
		}
		int idx = 0;
		for (int i = 1; i <= 26; i++) {
			if (Max == check[i]){
				idx = i+96;
				cnt++;
			}
		}
		if (cnt > 1) printf("?\n");
		else printf("%c\n", idx);

	}
	return 0;
}