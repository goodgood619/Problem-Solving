#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		if (n == 1) printf("1\n");
		else {
			int ans = 0;
			long long Max = 0;
				while (1) {
					if (n == 1) break;
					else {
						if (n % 2 == 1) {
							n = 3 * n + 1;
							Max = max(Max, n);
						}
						else if (n % 2 == 0){
							Max = max(Max, n);
							n /= 2;
						}
					}
				}
				printf("%lld\n", Max);
		}
	}
	return 0;
}