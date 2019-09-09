#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
P anspo[100000];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		anspo[i].first = y;
		anspo[i].second = x;
	}
	sort(anspo, anspo + n);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", anspo[i].second, anspo[i].first);
	}
	return 0;
}