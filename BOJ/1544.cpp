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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
string s[55];
map<string, int> m;
bool visited[55];
vector<vector<int>> a;
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) dfs(next);
	}
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		string here = s[i];
		string temp = here;
		memset(visited, false, sizeof(visited));
		for (int t = 0; t < here.size(); t++) {
				temp.push_back(temp[0]);
				temp.erase(temp.begin());
				for (int j = 0; j < n; j++) {
					if (i == j ||visited[j] ) continue;
					else {
						if (temp == s[j]) {
							visited[j] = true;
						}
					}
				}
			}
		for (int j = 0; j < n; j++) {
			if (visited[j]) {
				a[i].push_back(j);
			}
		}
	}
	int cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}