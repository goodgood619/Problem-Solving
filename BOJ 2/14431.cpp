#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;
int n;
int isprime[10005];
int stx, sty, enx, eny;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> pq;
int dist[10005];
vector<P> temp;
vector<vector<P>> a;
#define INF 99999999
void go() {
	for (int i = 2; i <= sqrt(10000); i++){
		if (isprime[i] == 0)continue;
		for (int j = i*i; j <= 10000; j += i) {
			isprime[j] = 0;
		}
	}
}
void dijk(int start) {
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (dist[vertex] < cost) continue;
		for (int i = 0; i < a[vertex].size(); i++) {
			int nextvertex = a[vertex][i].first;
			int nextcost = a[vertex][i].second;
			if (dist[nextvertex] > dist[vertex] + nextcost) {
				dist[nextvertex] = dist[vertex] + nextcost;
				pq.push({ nextcost,nextvertex });
			}
		}
 	}
}
int main(){
	for (int i = 2; i <= 10000; i++) { isprime[i] = i; }
	go();
	scanf("%d%d%d%d", &stx, &sty, &enx, &eny);
	temp.push_back({ stx,sty });
	temp.push_back({ enx,eny });
	scanf("%d", &n);
	a.resize(n+4);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		temp.push_back({ first,second });
	}
	int Size = temp.size();
	for (int i = 0; i < Size; i++) {
		for (int j = i; j < Size; j++) {
			if (i == j) continue;
			else{
				int x = abs(temp[i].first - temp[j].first);
				int y = abs(temp[i].second - temp[j].second);
				int Dist=sqrt(x*x + y*y);
				if (isprime[Dist] != 0) {
					a[i].push_back({ j,Dist });
					a[j].push_back({ i,Dist });
				}
			}
		}
	}
	for (int i = 0; i <= n + 4; i++) { dist[i] = INF; }
	dijk(0);
	if (dist[1] == INF) printf("-1\n");
	else printf("%d\n", dist[1]);
	return 0;
}