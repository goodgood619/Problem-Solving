#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
vector<P> ans;
vector<vector<int>> a;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n,m;
		scanf("%d", &n);
		ans.clear();
		a.clear();
		a.resize(n + 5);
		int Max = 0;
		for (int i = 1; i <= n; i++){
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
			Max = max(first, Max);
		}
		int startx = 0;
		int starty = 0;
		for (int i = 0; i <= Max; i++) {
			sort(a[i].begin(), a[i].end());
		}

		for (int i = 0; i <= Max; i++){
			if (a[i].size() == 0) continue;
			int endy = a[i][a[i].size()-1];
			int firsty = a[i][0];
			if (starty < endy) {
				for (int j = 0; j < a[i].size(); j++) {
					int nexty = a[i][j];
					ans.push_back({ i,nexty });
					starty = nexty;
				}
			}
			else if (starty > firsty) {
				for (int j = a[i].size() - 1; j >= 0; j--) {
					int nexty = a[i][j];
					ans.push_back({ i,nexty });
					starty = nexty;
				}
			}
			else if(starty==endy){
				ans.push_back({ i,starty });
			}
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int index;
			scanf("%d", &index);
			printf("%d %d\n", ans[index - 1].first, ans[index - 1].second);
		}
	}
	return 0;
}