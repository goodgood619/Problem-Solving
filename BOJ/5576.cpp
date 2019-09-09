#include <cstdio>
#include <algorithm>
using namespace std;
int w[10];
int k[10];
int main() {
	for (int i = 0; i < 10; i++) { scanf("%d", &w[i]);}
	for (int i = 0; i < 10; i++) { scanf("%d", &k[i]);}
	sort(w, w + 10);
	sort(k, k + 10);
	int wsum = 0;
	int ksum = 0;
	for (int i = 7; i <= 9; i++) { wsum += w[i];
	ksum += k[i];
	}
	printf("%d %d\n", wsum, ksum);
	return 0;
}