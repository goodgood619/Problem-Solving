#include <iostream>
#include <string.h>
using namespace std;
int sum = 0;
int go(int N) {
	if (N <= 9) {
		printf("0\n");
		return 0;
	}
	else {
		for (int i = 1; i <N; i++){
			sum=0;
			sum += i;
			for (int j = i;;) {
				sum += j % 10;
				j /= 10;
				if (j <= 0) {
					break;
				}
			}
			if (sum == N) {
				printf("%d", i);
				return 0;
			}
		}
	}
	if (sum != N) {
		printf("0");
		return 0;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	go(n);
}
