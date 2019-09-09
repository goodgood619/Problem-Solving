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
#define INF 1e9
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
int n, m,ans;
priority_queue<P, vector<P>, greater<P>> pq;
bool visited[205];
string s;
map<vector<int>, int> check;
vector<int> v;
void go(int index, int cnt, int depth) {
	if (cnt == 2) {
		if (check.count(v) == 1) return;
	}
	if (cnt == depth){
		vector<int> temp2;
		vector<int> temp3;
		temp2.push_back(v[1]);
		temp2.push_back(v[2]);
		if (check.count(temp2) == 1) return;
		temp3.push_back(v[0]);
		temp3.push_back(v[2]);
		if (check.count(temp3) == 1) return;
		ans++;
		return;
	}
	for (int i = index; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i + 1);
			go(i + 1, cnt + 1, depth);
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		vector<int> temp;
		for (int j = 1; j <= 2; j++) {
			int num;
			scanf("%d", &num);
			temp.push_back(num);
		}
		if (temp[0] > temp[1]) reverse(temp.begin(), temp.end());
		check[temp] = 1;
	}
	go(0, 0, 3);
	printf("%d\n", ans);
	return 0;
}