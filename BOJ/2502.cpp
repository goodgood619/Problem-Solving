#include <cstdio>
#include <algorithm>
using namespace std;
int D, K;
typedef pair <int, int> P;
P anspo[35];
int main(){
	scanf("%d%d", &D, &K);
	anspo[1].first = 1;
	anspo[2].second = 1;
	for (int i = 3; i <= D; i++) {
		anspo[i].first = anspo[i - 1].first + anspo[i - 2].first;
		anspo[i].second = anspo[i - 1].second + anspo[i - 2].second;
	}
	int totalx = 0;
	int totaly = 0;
	totalx = anspo[D].first;
	totaly = anspo[D].second;
	int a = 0;
	int b = 0;
	int ans1 = 0;
	int ans2 = 0;

	while (a*totalx + b*totaly != K) {
		if (a*totalx + b*totaly < K) {
			b++;
		}
		else if (a*totalx + b*totaly > K) {
			b = 0;
			a++;
		}
		else if (a*totalx + b*totaly == K) { 
			ans1 = a;
			ans2 = b;
			break;
		}
	}
	printf("%d\n", a);
	printf("%d\n", b);
	return 0;
}