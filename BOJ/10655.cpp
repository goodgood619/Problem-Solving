#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef pair<int, int> P;
P anspo[100005];
int dist[100005];
int n,total;
int Min = 999999999;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &anspo[i].first, &anspo[i].second);
		if (i >= 2) {
			dist[i] = abs(anspo[i].first - anspo[i - 1].first) + abs(anspo[i].second - anspo[i - 1].second);
			total += dist[i];
		}
	}
	for (int i = 2; i <= n - 2; i++) {
		int di = abs(anspo[i + 1].first - anspo[i - 1].first) + abs(anspo[i + 1].second - anspo[i - 1].second);
		Min = min(Min, total - dist[i] - dist[i + 1] +di);
	}
	printf("%d\n", Min);
	return 0;
}