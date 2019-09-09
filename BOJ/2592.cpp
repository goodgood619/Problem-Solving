#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[1001];
int sum, Cnt,idx;
int main() {
	for (int i = 0; i < 10; i++){
		int a;
		scanf("%d", &a);
		sum += a;
		cnt[a]++;
	}
	for (int i = 1; i <= 1000; i++) {
		if (Cnt < cnt[i]) {
			Cnt = cnt[i];
			idx = i;
		}
	}
	printf("%d\n", sum / 10);
	printf("%d\n", idx);
	return 0;
}