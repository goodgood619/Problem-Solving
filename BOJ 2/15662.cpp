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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int n,T, Case = 1, sum;
// 0:n극, 1:s극, 0,1,2,3,4,5,6,7: 0의 위치가 1일때, 1번톱니 1점, 2번톱니 2점, 3번톱니 4점, 4번 톱니 8점 획득
// 움직일때, 1번톱니:2, 2번톱니 2,6, 3번톱니 2,6 , 4번톱니 6을 통해 이동할수 있다. 0과 1 즉, 다르면 현재움직이는 톱니의 반대로 움직임
//1 : 시계방향, -1: 반시계방향
//(1,2),(2,1),(2,3),(3,2),(3,4),(4,3)
int topni[1001][8];
int make(int dir) {
	if (dir == 1) return -1;
	else return 1;
}
void move(int dir, int num) {
	int newtopni[1001][8] = { 0, };
	if (dir == 1) { //시계방향(0->1,1->2,2->3,...)
		for (int i = 0; i < 8; i++) {
			newtopni[num][(i + 1) % 8] = topni[num][i];
		}
		for (int i = 0; i < 8; i++) {
			topni[num][i] = newtopni[num][i];
		}
	}
	else { //반시계방향(0->7,1->0,2->1, 3->2 , ...
		for (int i = 0; i < 8; i++) {
			if (i == 0) newtopni[num][7] = topni[num][0];
			else newtopni[num][(i - 1) % 8] = topni[num][i];
		}
		for (int i = 0; i < 8; i++) {
			topni[num][i] = newtopni[num][i];
		}
	}
}
int check(int a, int b) {
	if (a == b) return 0;
	else return 1;
}
void go(int num, int dir) {
	// 6,2끼리 비교(0&0 -> 0이었다 망할)
	queue<P> q;
	bool visited[1005] = { false, };
	int rotate[1005] = { 0, };
	q.push({ num,dir });
	visited[num] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int dir = q.front().second;
		q.pop();
		rotate[here] = dir;
		if (here == 1) {
			if (!(topni[here][2] & topni[here + 1][6]) && !visited[here + 1] && check(topni[here][2], topni[here + 1][6])) {
				int newdir = make(dir);
				q.push({ here + 1,newdir });
				visited[here + 1] = true;
			}
		}
		else if (here == n) {
			if (!(topni[here][6] & topni[here - 1][2]) && !visited[here - 1] && check(topni[here][6], topni[here - 1][2])) {
				int newdir = make(dir);
				q.push({ here - 1,newdir });
				visited[here - 1] = true;
			}
		}
		else {
			if (!(topni[here][2] & topni[here + 1][6]) && !visited[here + 1] && check(topni[here][2], topni[here + 1][6])) {
				int newdir = make(dir);
				q.push({ here + 1,newdir });
				visited[here + 1] = true;
			}
			if (!(topni[here][6] & topni[here - 1][2]) && !visited[here - 1] && check(topni[here][6], topni[here - 1][2])) {
				int newdir = make(dir);
				q.push({ here - 1,newdir });
				visited[here - 1] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (rotate[i] == 0) continue;
		else move(rotate[i], i);
	}
}
int main(void) {
	sum = 0;
	int k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d ", &topni[i][j]);
		}
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int num, dir;
		scanf("%d%d", &num, &dir);
		go(num, dir);
	}
	for (int i = 1; i <= n; i++) {
		if (topni[i][0] == 1) sum ++;
	}
	printf("%d\n", sum);
	return 0;
}