#include <stdio.h>
#include <algorithm>
using namespace std;
int file[1001];
int n,clur;
long long si;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &file[i]);
	scanf("%d", &clur);

	for (int i = 1; i <= n; i++) {
		if (file[i] == 0) continue;
		int divide = file[i] / clur;
		int c = file[i] % clur;
		if (c == 0) {
			si += file[i];
		}
		else {
			si += ((divide*clur) + clur);
		}
	}
	printf("%lld\n", si);
	return 0;
}