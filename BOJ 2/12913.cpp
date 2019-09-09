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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n,k;
char board[51][51];
double dist[51][51];
vector<vector<pair<int, double>>> v;
double dijk(int here) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <=k; j++) {
			dist[i][j] = 1e9;
		}
	}
	
	for (int i = 0; i <= k; i++) dist[here][i] = 0;
	priority_queue<PPP, vector<PPP>, greater<PPP>> pq;
	pq.push({ 0,{here,k}});
	while (!pq.empty()) {
		double cost = pq.top().first;
		int here = pq.top().second.first;
		int magic = pq.top().second.second;
		if (here == 1) return cost;
		pq.pop();
		
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			double nextcost = v[here][i].second;
			if(magic>0){
				double p = nextcost;
				nextcost /= 2;
				if (dist[next][magic - 1] > dist[here][magic] + nextcost) {
					dist[next][magic - 1] = dist[here][magic] + nextcost;
					pq.push({ dist[next][magic - 1],{next,magic - 1} });
				}
				if (dist[next][magic] > dist[here][magic] + p) {
					dist[next][magic] = dist[here][magic] +p;
					pq.push({ dist[next][magic],{next,magic} });
				}
			}
			else {
				if (dist[next][magic] > dist[here][magic] + nextcost) {
					dist[next][magic] = dist[here][magic] + nextcost;
					pq.push({ dist[next][magic],{next,magic} });
				}
			}
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &k);
	v.resize(n + 1);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &board[i][j]);
			v[i].push_back({ j,(double)board[i][j] - '0' });
		}
	}

	printf("%.9lf",dijk(0));
	return 0;
}