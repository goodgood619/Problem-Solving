#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair <int, int> P;
P anspo[102];
int n;
int cnt = 1;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int weight, height;
		scanf("%d%d", &weight, &height);
		anspo[i].first = weight;
		anspo[i].second = height;
	}
	for (int i = 1; i <= n; i++){
		int lose = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (anspo[i].first < anspo[j].first && anspo[i].second < anspo[j].second) {
				lose++;
			}
			else continue;
		}
		printf("%d ", lose + 1);
	}
}