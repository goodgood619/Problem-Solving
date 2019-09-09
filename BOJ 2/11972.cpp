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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n, m, d, s;
vector<P> milk[55];
int p[55];
int main() {
	scanf("%d%d%d%d", &n, &m, &d, &s);
	for (int i = 1; i <= d; i++) {
		int p, mm, t;
		scanf("%d%d%d", &p, &mm, &t);
		milk[mm].push_back({ p,t });
	}
	for (int i = 1; i <= s; i++) {
		int person, sick;
		scanf("%d%d", &person, &sick);
		p[person] = sick;
	}
	for (int i = 1; i <= m; i++) {
		sort(milk[i].begin(), milk[i].end());
	}
	int Max = 0;
	for (int j = 1; j <= n; j++) {
		int sum = 0;
		map<int, int> check;
		map<int, int> check2;
		for (int i = 0; i < milk[j].size(); i++) {
			P here = milk[j][i];
			int pp = here.first, time = here.second;
			if (p[pp] >= time) {
				if (check.count(pp) == 0) {
					check[pp] = 1;
					check2[pp] = 1;
					sum++; //먹어서 아프게된원인
				}
			}
			if (p[pp] == 0 && time != 0) { //먹긴했는데, 아직 아프진 않은경우
				if (check2.count(pp) == 0) {
					check2[pp] = 1;
					sum++;
				}
			}
		}
		if (check.size()>=s) { //최소 아픈사람이 s명이상은되어야, 아픈우유라고 판단이 가능함
			Max = max(Max, sum);
		}
	}
	printf("%d\n", Max);
	return 0;
}