#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> arr;
vector<int> arr2;
vector<vector<int>> a;
vector<int> ans;
int path[60];
bool visited[60];
int n;
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (path[next] == -1 || dfs(path[next])) {
			path[next] = here;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d", &n);
	a.resize(55);
	bool odd = false;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (num % 2 == 0) arr2.push_back(num);
		else if (num % 2 == 1){
			if (i == 1) odd = true;
			arr.push_back(num);
		}
	}
	if (arr.size() != arr2.size()) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i <arr.size(); i++) {
		for (int j =0; j <arr2.size(); j++) {
			int num = arr[i] + arr2[j];
			bool check = false;
			for (int p = 2; p <= sqrt(num); p++){
				if (num%p == 0) {
					check = true;
					break;
				}
				else continue;
			}
			if (!check){
				if(odd) a[i].push_back(j);
				else a[j].push_back(i);
			}
		}
	}
	memset(path, -1, sizeof(path));
	for (int j = 0; j <a[0].size();j++){
		memset(path, -1, sizeof(path));
		int next = a[0][j];
		path[next] =0;
		int ok = 1;
		for (int i = 1; i < a.size(); i++) {
			if (a[i].size() == 0) continue;
			memset(visited, false, sizeof(visited));
			visited[0] = true;
			ok += dfs(i);
		}
		if (ok == n/2){
			int idx = 0;
			for (int i = 0; i <60; i++) {
				if (path[i] == 0) {
					idx = i;
					break;
				}
			}
			if(odd) ans.push_back(arr2[idx]);
			else ans.push_back(arr[idx]);
		}
	}
	if (ans.size() == 0) {
		printf("-1\n");
		return 0;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) { printf("%d ", ans[i]); }
	return 0;
}