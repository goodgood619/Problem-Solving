#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j =i; j <= n; j++) {
			if (i*j <= n) {
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}