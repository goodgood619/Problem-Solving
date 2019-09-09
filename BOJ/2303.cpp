#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,Max;
vector<int> v,temp;
bool visited[6];
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first != b.first) return a.first > b.first;
	if (a.second != b.second) return a.second > b.second;
}
void go(int index,int cnt, int depth) {
	if (cnt == depth) {
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			sum += (temp[i] % 10);
		}
		if (sum >=10) sum %= 10;
		if (Max < sum) {
			Max = sum;
		}
		return;
	}
	for (int i = index; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(i + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	vector<P> ans;
	for (int i = 1; i <= n; i++) {
		v.clear();
		Max = 0;
		for (int j = 1; j <= 5; j++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}
		go(0,0,3);
		ans.push_back({ Max,i });
	}
	sort(ans.begin(), ans.end(),compare);
	printf("%d\n", ans[0].second);
	return 0;
}