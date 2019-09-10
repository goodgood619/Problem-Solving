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
int n,ans=1e9;
char board[10][10];
int light[11];
vector<P> v;
void firstmake(int index,int k,int cnt) {
	if (index == 10) {
		v.push_back({ k,cnt });
		return;
	}
	firstmake(index + 1, k | (1 << index), cnt + 1);
	firstmake(index + 1, k, cnt);
}
void dfs(int pre,int here,int x,int cnt) {
	if (x == 10) {
		if (pre == 0) ans = min(ans, cnt);
		return;
	}

	if (x == 0) { //아예 처음행인경우
		for (int i = 0; i < v.size(); i++) {
			int	lhere = light[x];
			int lnext = light[x + 1];
			int state = v[i].first;
			for (int j = 0; j < 10; j++) {
				if (state & (1 << j)) { // 상태를 변화시키자
					lhere ^= (1 << j);//현재위치
					lnext ^= (1 << j);// 아래위치
					if (j - 1 >= 0) lhere ^= (1 << (j - 1)); //서쪽
					if (j + 1 < 10) lhere ^= (1 << (j + 1)); //동쪽
				}
			}
			dfs(lhere, lnext, x + 1, cnt +v[i].second);
		}
	}
	else { // 두번째행 그이하인경우
		int cnt2 = 0;
		int next = light[x + 1];
		for (int i = 0; i < 10; i++) {
			if (pre & (1 << i)) { //전상태가 비트가 켜져있다 즉 1이면, 꺼줘야한다
				cnt2++;
				here ^= (1 << i);// 현재
				if (i + 1 < 10) here ^= (1 << (i + 1)); //동
				if (i - 1 >= 0) here ^= (1 << (i - 1));// 서
				if(x+1<10) next ^= (1 << i);//남
			}
		}
		dfs(here, next, x + 1, cnt + cnt2);
	}
}
int main(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'O') light[i] |= (1 << j);
		}
	}

	firstmake(0, 0, 0);
	dfs(0,0,0,0);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}