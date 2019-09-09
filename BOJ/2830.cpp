#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int n, Max;
long long  cnt1[21];
long long  cnt0[21];
long long ans;
int arr[1000001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		Max = max(Max, arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		int p = Max;
		int a = arr[i];
		int k = 0;
		while (a >= 0) {
			if (a % 2 == 0) {
				cnt0[k]++;
				k++;
			}
			else {
				cnt1[k]++;
				k++;
			}
			a >>= 1;
			p >>= 1;
			if (p == 0) break;
		}
	}
	for (int i = 0; cnt1[i] != 0 || cnt0[i] != 0; i++) {
        long long sum=0;
        sum=pow(2, i)*cnt1[i] * cnt0[i];
            ans=ans+sum;
    }
printf("%lld\n", ans);
	return 0;
}