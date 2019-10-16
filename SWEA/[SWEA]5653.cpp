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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m,k;
int board[720][720];
int bfs() {
	queue<PPP> q;
	bool visited[720][720] = { false, };
	for (int i = 320; i < 320 + n; i++) {
		for (int j = 320; j < 320 + m; j++) {
			if (board[i][j] != 0) {
				q.push({ { i,j }, { board[i][j],0 } });
				visited[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		queue<PPP> temp;
		priority_queue<PP, vector<PP>> pq;
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int life = q.front().second.first;
			int flag = q.front().second.second;
			q.pop();
			if (flag == 0) { //비활성
				if (life == 1) {
					temp.push({ { x,y }, { board[x][y],1 } }); //바로 다음상태가 활성화상태일때
				}
				else temp.push({ { x,y }, { life - 1,0 } }); //그렇지않을때
			}
			else {
				if (board[x][y] == life) { //바로활성화상태일때, 4방향으로 퍼질수 있음
					if(board[x][y]>1) temp.push({ { x,y }, { board[x][y] - 1,1 } }); // 본인위치도 넣어주고
					for (int i = 0; i < 4; i++) {
						int nx = x + gox[i];
						int ny = y + goy[i];
						if (board[nx][ny] != 0) continue;
						else if(board[nx][ny]==0){
							pq.push({ board[x][y],{nx,ny} });
						}
					}
				}
				else {
					if (life>1) temp.push({ { x,y }, { life - 1,1 } });
				}
			}
		}
		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (board[x][y] < cost) {
				board[x][y] = cost;
				temp.push({ { x,y },{ board[x][y],0 } });
				visited[x][y] = true;
			}
		}
		ans = temp.size();
		q = temp;
	}
	return ans;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {	
		scanf("%d%d%d", &n, &m, &k);
		memset(board, 0, sizeof(board));
		for (int i = 320; i <320 + n; i++) {
			for (int j = 320; j < 320 + m; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		printf("#%d %d\n",Case++,bfs());
	}
	return 0;
}