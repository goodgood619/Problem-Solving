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
		int rest = n - i;
		int rest2 = -rest;
		if (rest >= 0) {
			for (int j = 1; j <= n; j++) {
				if (rest != 0){
					printf(" ");
					rest--;
					continue;
				}
				else printf("*");
			}
			printf("\n");
		}
		else{
			for (int j = 1; j <= n; j++) {
				if (rest2 != 0) {
					printf(" ");
					rest2--;
					continue;
				}
				else printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}