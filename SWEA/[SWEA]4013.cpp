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
#define mod 1000000009
#define lim 1000000000
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { -1,1,0,0 };
int goy[4] = { 0,0,-1,1 };
int t, Case = 1, k;
int topni[5][8];
void move(int num,int dir) {
	int newtopni[5][8] = { 0, };
	if (dir == 1) { //시계방향(0->1,1->2,
		for (int i = 0; i < 8; i++) {
			newtopni[num][(i+1)%8]=topni[num][i];
		}
		for (int i = 0; i < 8; i++) {
			topni[num][i]= newtopni[num][i];
		}
	}
	else if (dir == -1) { //반시계방향
		for (int i = 0; i < 8; i++) {
			newtopni[num][(i - 1+8) % 8] = topni[num][i];
		}
		for (int i = 0; i < 8; i++) {
			topni[num][i] = newtopni[num][i];
		}
	}
}
void go(int num, int dir) {
	queue<P> q;
	q.push({ num,dir });
	int rotate[5] = { 0, };
	bool visited[5] = { false, };
	visited[num] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int dir = q.front().second;
		q.pop();
		rotate[num] = dir;
		if (num == 1) { //맨 왼쪽
			if (topni[num][2] != topni[num + 1][6] && !visited[num+1]) {
				visited[num + 1] = true;
				if (dir == 1) q.push({ num + 1,-1 });
				else q.push({ num + 1,1 });
			}
		}
		else if (num == 4) { // 맨 오른쪽
			if (topni[num][6] != topni[num -1][2] && !visited[num - 1]) {
				visited[num - 1] = true;
				if (dir == 1) q.push({ num - 1,-1 });
				else q.push({ num - 1,1 });
			}
		}
		else { //중간톱니
			if (topni[num][2] != topni[num + 1][6] && !visited[num + 1]) {
				visited[num + 1] = true;
				if (dir == 1) q.push({ num + 1,-1 });
				else q.push({ num + 1,1 });
			}
			if (topni[num][6] != topni[num - 1][2] && !visited[num - 1]) {
				visited[num - 1] = true;
				if (dir == 1) q.push({ num - 1,-1 });
				else q.push({ num - 1,1 });
			}
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (rotate[i] == 0) continue;
		else move(i, rotate[i]);
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf(" %d", &topni[i][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= k; i++) {
			int num, dir;
			scanf("%d%d", &num, &dir);
			go(num, dir);
		}
		
		for (int i = 1; i <= 4; i++) {
			if (topni[i][0] == 1) ans += pow(2, i - 1);
		}
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}