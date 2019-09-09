#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
string s[1005][3];
map<string, int> m;
int Max;
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++){
			string a;
			cin >> a;
			s[i][j] = a;
		}
	}
	for (int i = 0; i < n; i++){
		m.clear();
		for (int j = 0; j < 3; j++) {
			m[s[i][j]]++;
		}
		int cnt = 0;
		for (int k = i + 1; k < n; k++){
			int same = 0;
			for (int p = 0; p < 3; p++){
				if (m.count(s[k][p]) != 0) same++;
			}
			if (same == 3) cnt++;
		}
		Max = max(Max, cnt);
	}
	printf("%d\n", Max+1);
	return 0;
}