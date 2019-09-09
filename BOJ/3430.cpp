#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <deque>
#include <queue>
#include <functional>
using namespace std;
int t,n,m;
typedef pair<int, int> P;
int parent[1000005];
int arr[1000005];
vector<int> ans;
vector<vector<int>> rain;
int find(int u) {
	if (parent[u] == u) return u;
	 return parent[u] = find(parent[u]);
}
void uni(int u, int v){
	 u = find(u);
	 v = find(v);
	if (u == v) return;
	parent[v] = u;

}
int main(){
	scanf("%d", &t);
	while (t--){
		bool check = false;
		scanf("%d%d", &n,&m);
		ans.clear();
		rain.clear();
		rain.resize(n + 1);
		memset(parent, 0, sizeof(parent));
		memset(arr, 0, sizeof(arr));
		priority_queue<P, vector<P>, greater<P>> pq;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] != 0) {
				rain[arr[i]].push_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!rain[i].empty()) { reverse(rain[i].begin(), rain[i].end());} // 호수가 여러번 비가오는걸 체크하기위한용도
		}
		for (int i = 1; i <= n; i++) {
			if (!rain[i].empty()){
				pq.push({ rain[i].back(),i });
				rain[i].pop_back(); // front_back이 안되가지고 ㅇㅇ
			}
		}
		for (int i = 1; i <= m; i++) {
			int what = arr[i];
			if (what == 0){
				//빼야하는데 더이상 비가 안와서 물을 그냥 애초에 먹을수없을때
				if (pq.empty()){
					ans.push_back(0);
					continue;
				}
				int lake=pq.top().second;
				//호수에 물이 있는경우 물먹기
				uni(0, lake);
				ans.push_back(lake);
				pq.pop(); //먹었으니 일끝남
			}
			else {
				int lake = find(what);
				if (lake != 0) {
					check = true;
					printf("NO\n");
					break;
				}
				else {
					parent[what] = what;
					if (rain[what].size() == 0) continue; //죽어도 더 올날이 없으므로 push할 이유가 없음
					else {
						pq.push({ rain[what].back(),what }); // 더올수있기때문에 무조건 push
						rain[what].pop_back();
					}
				}
			}
		}
		if (!check) {
			printf("YES\n");
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
// 반례: 81번째줄에 i가 안되는 이유
//1
//5 14
//0 0 0 0 1 3 0 4 1 0 1 5 0 3