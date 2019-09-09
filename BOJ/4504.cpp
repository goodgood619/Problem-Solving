#include <stdio.h>
#include <algorithm>
using namespace std;
int n,num;
int main(){
	scanf("%d", &n);
	while (1) {
		scanf("%d", &num);
		if (num == 0) break;
		if ((num%n) == 0) {
			printf("%d is a multiple of %d.\n", num, n);
		}
		else {
			printf("%d is NOT a multiple of %d.\n", num, n);
		}
	}
	return 0;
}