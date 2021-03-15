#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
int gox[8] = {0,1,-1,0,1,-1,1,-1};
int goy[8] = {1,0,0,-1,-1,1,1,-1};
struct p {
	int protein, fat, carbo, vitamin,price;
};
int ans = 1e9;
set<pair<int,vector<int>>> s;
void dfs(int idx,int cnt,int depth,int curMoney, 
	int curProtein,int curFat, int curCarbo, int curVitamin,
	int protein,int fat,int carbo, int vitamin, vector<bool> &visited, vector<p> &v) {
	if (cnt == depth) {
		if (curProtein >= protein && curFat >= fat && curCarbo >= carbo && curVitamin >= vitamin) {
			if (ans >= curMoney) {
				ans = curMoney;
				vector<int> temp;
				for (int i = 0; i < v.size(); i++) {
					if (visited[i]) {
						temp.push_back(i);
					}
				}
				s.insert({ curMoney,temp });
			}
		}
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, cnt + 1, depth, curMoney + v[i].price,
				curProtein + v[i].protein, curFat + v[i].fat, curCarbo + v[i].carbo, curVitamin + v[i].vitamin,
				protein, fat, carbo, vitamin, visited, v);
			visited[i] = false;
		}
	}
}
int main() {
	int n,protein,fat,carbo,vitamin;
	scanf("%d", &n);
	scanf("%d%d%d%d", &protein, &fat, &carbo, &vitamin);
	vector<p> v;
	for (int i = 0; i < n; i++) {
		int a, b, c, d,price;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &price);
		v.push_back({ a,b,c,d,price });
	}

	for (int i = 1; i <= n; i++) {
		vector<bool> visited;
		visited.assign(n, false);
		dfs(0, 0, i, 0, 0, 0, 0, 0, protein, fat, carbo, vitamin, visited, v);
	}

	if (ans == 1e9) printf("-1");
	else {
		auto ansArray = s.begin();
		int money = ansArray->first;
		vector<int> arr = ansArray->second;
		printf("%d\n", money);
		for (auto e : arr) {
			printf("%d ", e + 1);
		}
		
	}
	return 0;
}