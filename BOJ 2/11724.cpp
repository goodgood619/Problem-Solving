#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
queue <P> q;
vector <vector<int>> adj;
int n, m;//정점, 간선
int first, second;
int check[1000001];
int cnt;
void dfs(int now) {
	check[now] = 1;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> first >> second;
		adj[first].push_back(second);
		adj[second].push_back(first);
	}
	for (int i = 1; i <=n; i++) {
		if (!check[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << endl;
}
