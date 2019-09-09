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
using namespace std;
typedef long long ll;
int start,en,t;
bool visited[10005];
char route[10005];
int parent[10005];
queue<int> q;
void D(int num){
	int nx = num * 2;
	if (nx > 9999) nx %= 10000;
	if (!visited[nx]) {
		visited[nx] = true;
		route[nx] = 'D';
		parent[nx] = num;
		q.push(nx);
	}
}
void S(int num){
	int nx = num - 1;
	if (nx<0) nx = 9999;
	if (!visited[nx]) {
		visited[nx] = true;
		route[nx] = 'S';
		parent[nx] = num;
		q.push(nx);
	}
}
void L(int num){
	int nx = (num % 1000) * 10 + (num / 1000);
	if (!visited[nx]) {
		visited[nx] = true;
		route[nx] = 'L';
		parent[nx] = num;
		q.push(nx);
	}
}
void R(int num){
	int nx= (num % 10) * 1000 + (num / 10);
	if (!visited[nx]) {
		visited[nx] = true;
		route[nx] = 'R';
		parent[nx] = num;
		q.push(nx);
	}
}
void bfs(int start){
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int num = q.front();
		if (num == en){
			break;
		}
		q.pop();
		D(num);
		S(num);
		L(num);
		R(num);
	}
	while (!q.empty()) {
		q.pop();
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(parent, -1, sizeof(parent));
		memset(route, 0, sizeof(route));
		scanf("%d%d", &start, &en);
		bfs(start);
		string ans;
		int p = en;
		while (p != start) {
			ans.push_back(route[p]);
			p = parent[p];
		}
		reverse(ans.begin(), ans.end());
		printf("%s\n", ans.c_str());
	}
	return 0;
}