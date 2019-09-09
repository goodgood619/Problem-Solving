#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int cnt = 1;
	int cnt2 = n - 1;
	for (int i = 1; i <= 2 * n - 1; i++){
		if (cnt <= n) {
			for (int j = 1; j <= i; j++) {
				printf("*");
			}
			printf("\n");
		}
		else {
			for (int j = 1; j <= cnt2; j++) {
				printf("*");
			}
			printf("\n");
			cnt2--;
		}
		cnt++;
	}
	return 0;
}