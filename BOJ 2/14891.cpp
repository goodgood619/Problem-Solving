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
	int num;
	int rotate;
};
void go(int n,int dir,int **temptopni,int **topni,int *visited) {
	if (n == -1 || n == 4 || visited[n]) return;
	visited[n] = 1;
	if (dir == -1) { //반시계
		int top = topni[n][0];
		for (int i = 0; i < 7; i++) temptopni[n][i] = topni[n][i + 1];
		temptopni[n][7] = top;
	}
	else { //시계
		int top = topni[n][7];
		for (int i = 7; i > 0; i--) temptopni[n][i] = topni[n][i - 1];
		temptopni[n][0] = top;
	}
	if (n-1>=0&& topni[n - 1][2] != topni[n][6]) go(n-1,dir*-1,temptopni,topni,visited);//서쪽
	if ( n+1<4 && topni[n + 1][6] != topni[n][2]) go(n+1,dir*-1,temptopni,topni,visited);//동쪽
}
void reset(int **temptopni) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			temptopni[i][j] = 0;
		}
	}
}
int main() {
	int** topni = new int*[4];
	int** temptopni = new int* [4];
	int* visited = new int[4];
	for (int i = 0; i < 4; i++) visited[i] = 0;
	for (int i = 0; i < 4; i++) {
		topni[i] = new int[8];
		temptopni[i] = new int[8];
	}
	reset(temptopni);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %1d", &topni[i][j]);
		}
	}
	int k;
	scanf("%d", &k);
	vector<position> v;
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf(" %d%d", &a, &b);
		go(a-1, b,temptopni,topni,visited);
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 8; k++) {
				if (visited[j]) {
					topni[j][k] = temptopni[j][k];
				}
			}
		}
		for (int j = 0; j < 4; j++) visited[j] = 0;
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) if (topni[i][0] == 1) ans += pow(2, i);
	printf("%d\n", ans);
	return 0;
}