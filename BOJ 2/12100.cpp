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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
vector<vector<int>> board;
int n,ans;
void make(int dir) {
	deque<int> q[25],temp[25];
	vector<vector<int>> newboard(n,vector<int>(n));
	if (dir == 0) { // 동쪽
		for (int i = 0; i < n; i++) {
			for (int j = n-1; j>=0; j--) {
				if(board[i][j]!=0) q[i].push_back(board[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			while (!q[i].empty() && q[i].size()>=2) {
				int first = q[i].front();
				q[i].pop_front();
				int second = q[i].front();
				q[i].pop_front();
				if (first != second) {
					temp[i].push_back(first);
					q[i].push_front(second);
				}
				else {
					temp[i].push_back(first + second);
				}
			}
			if (!q[i].empty()) {
				temp[i].push_back(q[i].front());
				q[i].pop_back();
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (temp[i].empty()) break;
				newboard[i][j]=temp[i].front();
				temp[i].pop_front();
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				board[i][j]=newboard[i][j];
			}
		}
	}
	else if (dir == 1) { // 북쪽
		for (int j =0;j<n;j++) {
			for (int i = 0; i<n;i++) {
				if(board[i][j]!=0) q[j].push_back(board[i][j]);
			}
		}

		for (int j = 0; j < n; j++) {
			while (!q[j].empty() && q[j].size() >= 2) {
				int first = q[j].front();
				q[j].pop_front();
				int second = q[j].front();
				q[j].pop_front();
				if (first != second) {
					temp[j].push_back(first);
					q[j].push_front(second);
				}
				else {
					temp[j].push_back(first + second);
				}
			}
			if (!q[j].empty()) {
				temp[j].push_back(q[j].front());
				q[j].pop_back();
			}
		}

		for (int j = 0; j<n; j++) {
			for (int i = 0; i<n; i++) {
				if (temp[j].empty()) break;
				newboard[i][j] = temp[j].front();
				temp[j].pop_front();
			}
		}
		for (int j = 0; j<n; j++) {
			for (int i = 0; i<n; i++) {
				board[i][j] = newboard[i][j];
			}
		}
	}
	else if (dir == 2) { // 서쪽
		for (int i = 0; i < n; i++) {
			for (int j = 0; j<n; j++) {
				if(board[i][j]!=0) q[i].push_back(board[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			while (!q[i].empty() && q[i].size() >= 2) {
				int first = q[i].front();
				q[i].pop_front();
				int second = q[i].front();
				q[i].pop_front();
				if (first != second) {
					temp[i].push_back(first);
					q[i].push_front(second);
				}
				else {
					temp[i].push_back(first + second);
				}
			}
			if (!q[i].empty()) {
				temp[i].push_back(q[i].front());
				q[i].pop_back();
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j<n; j++) {
				if (temp[i].empty()) break;
				newboard[i][j] = temp[i].front();
				temp[i].pop_front();
			}
		}
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				board[i][j] = newboard[i][j];
			}
		}
	}
	else { //남쪽
		for (int j = 0; j<n; j++) {
			for (int i = n-1; i>=0; i--) {
				if(board[i][j]!=0) q[j].push_back(board[i][j]);
			}
		}

		for (int j = 0; j < n; j++) {
			while (!q[j].empty() && q[j].size() >= 2) {
				int first = q[j].front();
				q[j].pop_front();
				int second = q[j].front();
				q[j].pop_front();
				if (first != second) {
					temp[j].push_back(first);
					q[j].push_front(second);
				}
				else {
					temp[j].push_back(first + second);
				}
			}
			if (!q[j].empty()) {
				temp[j].push_back(q[j].front());
				q[j].pop_back();
			}
		}

		for (int j = 0; j<n; j++) {
			for (int i = n-1; i>=0; i--) {
				if (temp[j].empty()) break;
				newboard[i][j] = temp[j].front();
				temp[j].pop_front();
			}
		}
		for (int j = 0; j<n; j++) {
			for (int i = n-1; i>=0; i--) {
				board[i][j] = newboard[i][j];
			}
		}
	}
}
void dfs(int cnt,int depth) {
	if (cnt == depth) {
		int Max = 0;
		for (int i = 0; i < n; i++) {
			for (int j =0; j < n; j++) {
				Max = max(Max, board[i][j]);
			}
		}
		ans = max(ans, Max);
		return;
	}
	vector<vector<int>> Copy(n,vector<int>(n));
	for (int i = 0; i < 4; i++) {
		Copy = board;
		make(i);
		dfs(cnt + 1, depth);
		board = Copy; //다시 전상태 원상복구
	}
}
int main() {
	scanf("%d", &n);
	board.resize(n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			board[i].push_back(num);
		}
	}
	dfs(0, 5);
	printf("%d\n", ans);
	return 0;
}