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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
struct position {
	
};
void go(int here,int cnt,int depth,int &ans,int **board,int *visited,int n) {
	if (cnt == depth) {
		vector<int> v1, v2; // v1 startteam, v2 linkteam
		for (int i = 0; i < n; i++) {
			if (visited[i]) v1.push_back(i);
			else v2.push_back(i);
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < v1.size(); i++) {
			for (int j = i + 1;j< v1.size(); j++) {
				int here = v1[i], next = v1[j];
				sum1 += board[here][next], sum1 += board[next][here];
			}
		}
		for (int i = 0; i < v2.size(); i++) {
			for (int j = i + 1;j< v2.size(); j++) {
				int here = v2[i], next = v2[j];
				sum2 += board[here][next], sum2 += board[next][here];
			}
		}
		ans = min(ans, abs(sum1 - sum2));
		return;
	}
	for (int i = here; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			go(i + 1, cnt + 1, depth, ans, board,visited, n);
			visited[i] = 0;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int** board = new int*[n + 1];
	int* visited = new int[n + 1];
	for (int i = 0; i <= n; i++) board[i] = new int[n + 1];
	for (int i = 0; i <= n; i++) visited[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int ans = 1e9;
	go(0, 0, n / 2,ans,board,visited,n);
	printf("%d\n", ans);
	return 0;
}