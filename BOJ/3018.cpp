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
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,e,k;
map<int, vector<int>> m;
int main() {
	scanf("%d%d", &n, &e);
	vector<vector<int>> v;
	int song = 1;
	for (int i = 1; i <= e; i++) {
		scanf("%d", &k);
		vector<int> temp;
		int New = 0;
		for (int j = 1; j <= k; j++) {
			int num;
			scanf("%d", &num);
			temp.push_back(num);
			if (num == 1) New = 1;
		}
		v.push_back(temp);
		if (New) {
			for (int j = 0; j < temp.size(); j++) {
				int who = temp[j];
				m[who].push_back(song);
			}
			song++;
		}
		else { //노래공유
			for (int j = 0; j < temp.size(); j++) {
				int who = temp[j];
				vector<int> knowsong = m[who];
				for (int k = 0; k < temp.size(); k++) {
					if (j == k) continue;
					else {
						int who2 = temp[k];
						vector<int> knowsong2 = m[who2];
						for (int p = 0; p < knowsong.size(); p++) {
							int song1 = knowsong[p];
							int same = 0;
							for (int q = 0; q < knowsong2.size(); q++) {
								int song2 = knowsong2[q];
								if (song1 == song2) {
									same = 1; break;
								}
							}
							if (!same) m[who2].push_back(song1);
						}
					}
				}
			}
		}
	}
	map<int, vector<int>>::iterator it;
	song--;
	vector<int> ans;
	for (it = m.begin(); it != m.end(); it++) {
		if (song == it->second.size()) {
			ans.push_back(it->first);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
	return 0;
}