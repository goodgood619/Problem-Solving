#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
P anspo[505];
bool visited[505];
int n,m,ok;
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		anspo[i].first = first;
		anspo[i].second = second;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int what;
		scanf("%d", &what);
		visited[what] = true;
		for (int j = 1; j <= n; j++) {
			if (anspo[j].first == what) {
				anspo[j].first = 0;
			}
			if (anspo[j].second == what) {
				anspo[j].second = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (anspo[i].first != 0 && anspo[i].second != 0 && !visited[i]) ok++;
	}
	printf("%d\n", ok);
	return 0;
}