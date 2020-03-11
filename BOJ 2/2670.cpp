#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	double arr[10000] = { 0.0, };
	for (int i = 0; i < n; i++) {
		scanf("%lf", &arr[i]);
	}
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double temp = arr[i];
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, temp);
			temp *= arr[j];
		}
	}
	printf("%.3lf\n", ans);
	return 0;
}