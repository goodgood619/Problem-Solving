#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
using namespace std;
typedef long long ll;
#define INF 1e9
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
int n;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
map<string, int> m;
string ans;
int main(){
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		m[s]++;
		s.clear();
	}
	map<string, int>::iterator it;
	int Max = 0;
	for (it = m.begin(); it != m.end(); it++) {
		if (Max < it->second) {
			Max = it->second;
			ans.clear();
			ans=it->first;
		}
	}
	printf("%s\n", ans.c_str());
	return 0;
}