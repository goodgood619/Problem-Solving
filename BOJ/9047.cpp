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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n,Max,Min;
vector<int> v,temp;
bool visited[6];
void go(int index, int cnt, int depth) {
	if (cnt == depth) {
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			sum+=temp[i] * pow(10, temp.size() - 1 - i);
		}
		Max = max(Max, sum);
		Min = min(Min, sum);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(index + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int cnt = 0;
		while (n != 6174) {
			Max = 0;
			Min = 10000;
			memset(visited, false, sizeof(visited));
			int p = n;
			v.clear();
			temp.clear();
			int c = 0;
			while (c<4) {
				v.push_back(p % 10);
				p /= 10;
				c++;
			}
			go(0, 0, 4);
			cnt++;
			n = Max - Min;
		}
		printf("%d\n", cnt);
	}
	return 0;
}