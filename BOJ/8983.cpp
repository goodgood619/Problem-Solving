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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, l;
vector<int> sa;
vector<P> an;
int main() {
	scanf("%d%d%d", &m, &n, &l);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d ", &num);
		sa.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		an.push_back({ x,y });
	}
	sort(sa.begin(), sa.end());
	sort(an.begin(), an.end());
	int cnt = 0;
	int sptr = 0, aptr = 0;
	while (sptr < sa.size() && aptr < an.size()) {
		int dist = abs(an[aptr].first - sa[sptr]) + an[aptr].second;
		if (dist <= l) {
			aptr++;
			cnt++;
		}
		else {
			while (sptr!= m-1 && sa[sptr+1] < an[aptr].first) {
				sptr++;
			}
			if (abs(sa[sptr] - an[aptr].first) + an[aptr].second <= l) { //가장가까운 현재위치
				cnt++;
				aptr++;
				continue;
			}
			if (sptr != m-1 && abs(sa[sptr+1] - an[aptr].first) + an[aptr].second <= l) { //그다음위치사대
				cnt++;
				aptr++;
				continue;
			}
			aptr++; //둘다아니면 그냥 동물위치 증가
		}
	}
	printf("%d\n", cnt);
	return 0;
}