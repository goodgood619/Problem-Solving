#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int n;
typedef long long ll;
long long arr[5010];
const ll INF = LLONG_MAX;
long long Min = INF;
long long sum;
long long num[3];
long long a, b, c;
int start, last;
int main() {

	scanf("%d", &n);
	for (int i = 0; i <n; i++)
		scanf("%lld", &arr[i]);

	sort(arr, arr + n);

	for (int i = 0; i <= n - 3; i++) {
		a = arr[i];
		start = i + 1;
		last = n - 1;
		while (start < last) {
			b = arr[start];
			c = arr[last];
			sum = abs(a + b + c);

			if (a + b + c == 0)
			{
				num[0] = arr[i];
				num[1] = arr[start];
				num[2] = arr[last];
				break;
			}
			else if (a + b + c > 0) {
				if (Min > sum) {
					Min = sum;
					num[0] = arr[i];
					num[1] = arr[start];
					num[2] = arr[last];
				}
				last = last - 1;
			}
			else {
				if (Min > sum) {
					Min = sum;
					num[0] = arr[i];
					num[1] = arr[start];
					num[2] = arr[last];
				}
				start = start + 1;
			}

		}
	}
	printf("%lld %lld %lld\n", num[0], num[1], num[2]);
	return 0;
}