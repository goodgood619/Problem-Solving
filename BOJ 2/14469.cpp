#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair <int, int> P;
int n,sum;
P anspo[100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &anspo[i].first, &anspo[i].second);
	}
	sort(anspo, anspo + n);
	if (n >= 2) {
		for (int i = 0; i < n - 1; i++) {
			int a = anspo[i].first;
			int b = anspo[i].second;
			if (a + b < anspo[i + 1].first) { sum = anspo[i + 1].first; }
			else {
				sum = a + b;
				anspo[i + 1].first = a + b;
			}
		}
		sum += anspo[n - 1].second;
		printf("%d\n", sum);
	}
	else printf("%d\n", anspo[0].first + anspo[0].second);
	return 0;
}