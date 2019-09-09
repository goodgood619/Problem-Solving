#include <stdio.h>
#include <algorithm>
using namespace std;
int make[15001];
int m,n,cnt;
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; i++) { scanf("%d", &make[i]);}
	sort(make + 1, make + n + 1);
	int left = 1;
	int right = n;
	for (; left < right;) {
		if (make[left] + make[right] < m) {
			left++;
			continue;
		}
		else if (make[left] + make[right] > m) {
			right--;
			continue;
		}
		else if (make[left] + make[right] == m) {
			cnt++;
			right--;
		}
	}
	printf("%d\n", cnt);
	return 0;
}