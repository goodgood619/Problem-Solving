
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int t,root,p,q,ans;
int indegree[10004];
int route1[10004];
int route2[10004];
vector<vector<int>> a;
void go(int num) {
	if (num == root){
		return;
	}
	else {
		int next = a[num][0];
		route1[p++] = next;
		go(next);
	}
}
void go2(int num) {
	if (num == root) { 
		return; }
	else {
		int next = a[num][0];
		route2[q++] = next;
		go2(next);
	}
}
int main(){
	scanf("%d", &t);
	while (t--){
		a.clear();
		int n,num1,num2;
		memset(indegree, 0, sizeof(indegree));
		memset(route1, 0, sizeof(route1));
		memset(route2, 0, sizeof(route2));
		p = 0;
		q = 0;
		ans = 0;
		scanf("%d", &n);
		a.resize(n + 1);
		for (int i = 1; i < n; i++) {
			int parent, child;
			scanf("%d%d", &parent, &child);
			a[child].push_back(parent);
			indegree[child]++;
		}
		scanf("%d%d", &num1, &num2);
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				root = i;
			}
			else continue;
		}
		route1[0] = -1;
		route2[0] = -1;
		route1[1] = num1;
		route2[1] = num2;
		p += 2;
		q += 2;
		go(num1);
		go2(num2);
		p--;
		q--;
		while (1){
			if (route1[p] == route2[q]) {
				p--;
				q--;
				continue;
			}
			else {
				ans = route1[++p];
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}