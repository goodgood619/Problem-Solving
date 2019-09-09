#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int board[1003][1003];
int indegree[1003];
int outdegree[1003];
typedef pair<int, int> P;
vector<vector<P>> a;
vector<int> circuit;
int n;
void oiler(int here, vector<int>& circuit) {
	for (int i = 0; i < a[here].size(); i++) {
		while (a[here][i].second > 0){
			int next = a[here][i].first;
			int newhere = 0;
			a[here][i].second--;
			for (int j = 0; j < a[next].size(); j++) {
				if (a[next][j].first == here) {
					newhere = j;
					break;
				}
			}
			a[next][newhere].second--;
			oiler(a[here][i].first, circuit);
		}
	}
	circuit.push_back(here);
}
int main(){
	scanf("%d", &n);
	a.resize(n + 1);
	bool check=false;
	int total = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			a[i].push_back({ j,board[i][j] });
			outdegree[i] += board[i][j];
			total += board[i][j];
		}
	}
	int hal = 0;
	for (int i = 1; i <= n; i++) {
		if (outdegree[i]% 2 == 0) continue;
		else check = true;
	}
	if (!check) {
		if (hal == 0) {
			oiler(1, circuit);
			int Size = circuit.size();
			if ((total / 2) + 1 != Size) check = true;
			if (!check) {
				for (int i = Size - 1; i >= 0; i--) {
					printf("%d ", circuit[i]);
				}
			}
		}
	}
	else if(check)printf("-1\n");
	return 0;
}