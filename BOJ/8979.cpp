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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, k;
int ranking[1001];
bool visited[1001];
struct PPPPP {
	int nation, gold, silver, bronze;
};
bool compare(const PPPPP &a,const PPPPP &b) {
	if (a.gold != b.gold) return a.gold > b.gold;
	if (a.silver != b.silver) return a.silver > b.silver;
	if (a.bronze != b.bronze)return a.bronze > b.bronze;
	if (a.nation != b.nation) return a.nation < b.nation;
}
int main() {
	scanf("%d%d", &n, &k);
	vector<PPPPP> v;
	for (int i = 1; i <= n; i++) {
		int nation, gold, silver, bronze;
		scanf("%d%d%d%d", &nation, &gold, &silver, &bronze);
		v.push_back({ nation,gold,silver,bronze });
	}
	sort(v.begin(), v.end(), compare);

	int rank = 1;
	for (int i = 0; i < v.size(); i++) {
		if (visited[v[i].nation]) continue;
		rank = i + 1;
		if (!visited[v[i].nation]) {
			ranking[v[i].nation] = rank;
			visited[v[i].nation] = true;
		}
		for (int j = i + 1; j< v.size(); j++) {
			if (v[i].gold != v[j].gold || v[i].silver != v[j].silver || v[i].bronze != v[j].bronze){
				break;
			}
			else {
				ranking[v[j].nation] = rank;
				visited[v[j].nation] = true;
			}
		}
	}
	printf("%d\n", ranking[k]);
	return 0;
}