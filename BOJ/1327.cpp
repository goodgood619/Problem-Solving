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
int n, k;
map<vector<int>,int> m;
map<int, vector<int>> mm;
int dist[40500];
bool visited[40500];
void bfs(vector<int> v,int here) {
	queue<int> q;
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == 1) return;
		vector<int> temp = mm[here];
		for (int i = 0; i < temp.size() - k + 1; i++) { // 여기는 뒤집는 부분을 집어넣기 위함,처음이 될수 있고 중간이 될수있
			vector<int> origin;
			for (int k = 0; k < i; k++) { // 앞쪽넣기
					origin.push_back(temp[k]);
				}
				vector<int> temp2;
				for (int j = i; j < i + k; j++) {
					temp2.push_back(temp[j]);
				}
				reverse(temp2.begin(), temp2.end());
				for (int j = 0; j < temp2.size(); j++) { // 뒤집은거 넣기
					origin.push_back(temp2[j]);
				}
				for (int p = i + k; p < temp.size(); p++) { // 남은거 넣기
					origin.push_back(temp[p]);
				}
				int next = m[origin];
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
					dist[next] = dist[here] + 1;
				}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	vector<int> v,temp;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	temp = v;
	sort(temp.begin(), temp.end());
	int start = 1;
	do {
		if (m.count(temp) == 0) {
			m[temp] = start;
			mm[start] = temp;
			start++;
		}
	} while (next_permutation(temp.begin(), temp.end()));
	start = m[v];
	if (start == 1) {
		printf("0\n");
		return 0;
	}
	bfs(v,start);
	dist[1] == 0 ? printf("-1\n") : printf("%d\n", dist[1]);
	return 0;
}