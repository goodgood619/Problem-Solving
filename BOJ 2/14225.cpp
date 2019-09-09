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
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int ans = INT_MAX;
vector<int> v,temp;
map<int, int> m;
bool visited[25];
void go(int index, int cnt, int depth) {
	if (cnt == depth){
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) { sum += temp[i];}
		if (m.count(sum) == 0) {
			m[sum] = 1;
		}
		return;
	}
	for (int i = index; i <v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(i + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= v.size(); i++) {
		go(0, 0, i);
		memset(visited, false, sizeof(visited));
	}

	bool ok = false;
	int Max = 0;
	map<int, int>::iterator it;
	int first = m.begin()->first;
	if (first == 1) {
		for (it = m.begin(); it != m.end(); it++) {
			Max = max(Max, it->first);
			if (it == m.begin()) continue;
			if (it->first - first == 1) {
				first = it->first;
				continue;
			}
			else {
				printf("%d\n", first + 1);
				ok = true;
				break;
			}
		}
		if (!ok) {
			printf("%d\n", Max + 1);
		}
	}
	else printf("1\n");
	return 0;
}