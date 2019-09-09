#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, Max,real;
int money[10001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &money[i]);
		real+= money[i];
		Max = max(money[i], Max);
	}
	scanf("%d", &m);
	sort(money + 1, money + n + 1);
	if (real<= m) { printf("%d\n", Max);}
	else {
		int left = 1;
		int right = m;
		int mid = (left + right) / 2;
		while (left <= right) {
			int sum = 0;
			mid = (left + right) / 2;
			for (int i = 1; i <= n; i++) {
				if (mid > money[i]) sum += money[i];
				else sum += mid;
			}
			if (sum > m) right = mid - 1;
			else left = mid + 1;
		}
		left -= 1;
		printf("%d\n", left);
	}
	return 0;
}

