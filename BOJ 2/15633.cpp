#include <cstdio>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int n,sum;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0) {
			if (i != (n / i)) {
				sum += i;
				sum += (n / i);
			}
			else {
				sum += i;
			}
		}
	}
	printf("%d\n", sum*5-24);
	return 0;
}