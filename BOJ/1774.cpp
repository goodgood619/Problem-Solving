#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
int n, m;
void merge(int a, int b);
int find(int idx), par[1001];
vector<pair<double, double>> path;
double dist(int a, int b);
int main(void) {
	fill(par, par + 1001, -1);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		path.push_back({ a,b });
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int atop = find(a), btop = find(b);
		if (atop != btop) {
			merge(a, b);
			cnt++;
		}
	}
	for (int i = 0; i <path.size(); i++) {
		for (int j = i + 1; j <path.size(); j++) {
			double x = pow((path[i].first - path[j].first), 2.0);
			double y = pow((path[i].second - path[j].second), 2.0);
			double res = sqrt(x + y);
			pq.push({ res,{ i + 1,j + 1 } });
		}
	}
	double sum = 0;
	while (cnt!=n-1) {
		double cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (find(x) != find(y)) {
			merge(x, y);
			cnt++;
			sum += cost;
		}
	}
	printf("%.2lf\n", sum);
	return 0;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
}
int find(int idx) {
	if (par[idx] < 0) return idx;
	return par[idx] = find(par[idx]);
}