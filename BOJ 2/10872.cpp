#include <stdio.h>
int fac(int n) {
	if (n == 0) { return 1;}
	else return n*fac(n - 1);
}
int main() {
	int input;
	scanf("%d", &input);
	printf("%d\n", fac(input));
	return 0;
}