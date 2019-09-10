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
int n, ans = 1e9;
int board[19][19];
int light[19];
vector<P> v;
void firstmake(int index, int k, int cnt) {
	if (index == n) {
		v.push_back({ k,cnt });
		return;
	}
	firstmake(index + 1, k | (1 << index), cnt + 1);
	firstmake(index + 1, k, cnt);
}
void dfs(int x, int cnt) {
	if (x == n) {
		if (light[x-1]==0) ans = min(ans, cnt);
		return;
	}

	if (x == 0) { //아예 처음행인경우
		for (int i = 0; i < v.size(); i++) {
			int	lhere = light[x];
			int lnext = light[x + 1];
			int backhere = light[x], backnext = light[x + 1];
			int state = v[i].first;
			for (int j = 0; j < n; j++) {
				if (state & (1 << j)) { // 상태를 변화시키자
					light[x] ^= (1 << j);//현재위치
					light[x+1] ^= (1 << j);// 아래위치
					if (j - 1 >= 0) light[x] ^= (1 << (j - 1)); //서쪽
					if (j + 1 < n) light[x] ^= (1 << (j + 1)); //동쪽
				}
			}
			dfs(x + 1, cnt + v[i].second);
			light[x] = backhere, light[x + 1] = backnext; //원상복구
		}
	}
	else { // 두번째행 그이하인경우
		int cnt2 = 0;
		int pre = light[x - 1];
		int here = light[x];
		int next = light[x + 1];
		for (int i = 0; i < n; i++) {
			if (light[x-1] & (1 << i)) { //전상태가 비트가 켜져있다 즉 1이면, 꺼줘야한다
				cnt2++;
				light[x-1] ^= (1 << i); // 북쪽 변화
				light[x] ^= (1 << i);// 현재
				if (i + 1 < n) light[x] ^= (1 << (i + 1)); //동
				if (i - 1 >= 0) light[x] ^= (1 << (i - 1));// 서
				if (x + 1<n) light[x+1] ^= (1 << i);//남
			}
		}
		dfs(x + 1, cnt + cnt2);
		light[x + 1] = next, light[x] = here, light[x - 1] = pre; //원상복구
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 1) light[i] |= (1 << j);
		}
	}

	firstmake(0, 0, 0);
	dfs(0, 0);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}