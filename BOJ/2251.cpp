#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n, m, stx, sty;
bool visited[205][205];
int a, b, c;
vector<int> ans;
void dfs(int herea, int hereb, int herec){
	if (visited[herea][hereb]) return;
	if (herea == 0){
		ans.push_back(herec);
	}
	visited[herea][hereb] = true;
	// a->b로 가는 경우 근데 물이 많은 경우
	if (herea + hereb >b){
		dfs(herea + hereb -b, b, herec);
	}
	else {
		dfs(0, herea + hereb, herec);
	}
	// b->a
	if (herea + hereb >a) {
		dfs(a, herea + hereb - a, herec);
	}
	else{
		dfs(herea + hereb, 0, herec);
	}
	// a->c
	if (herea + herec>c){
		dfs(herea + herec -c, hereb, c);
	}
	else dfs(0, hereb, herea + herec);
	//c->a
	if (herea + herec >a) {
		dfs(a, hereb, herea + herec -a);
	}
	else dfs(herea + herec, hereb, 0);
	//b->c
	if (hereb + herec >c) {
		dfs(herea, hereb + herec -c, c);
	}
	else dfs(herea, 0, hereb + herec);
	//c->b
	if (hereb + herec >b) {
		dfs(herea, b, hereb + herec -b);
	}
	else dfs(herea, hereb + herec, 0);
}
int main(){
	scanf("%d%d%d", &a, &b,&c);
	dfs(0, 0, c);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}