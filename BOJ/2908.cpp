#include <cstdio>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char a[5];
char b[5];
int sum1, sum2;
int main() {
	scanf("%s%s", a, b);
	int length = strlen(a);
	for (int i = 0; i <1; i++) {
		char temp = a[i];
		a[i] = a[length - 1 - i];
		a[length - i-1] = temp;
		char temp2 = b[i];
		b[i] = b[length - 1 - i];
		b[length - 1 - i] = temp2;
	}

	for (int i = 0; i < length; i++){
		int num = a[i] - '0';
		int num2 = b[i] - '0';
		sum1 += num*pow(10, length - 1 - i);
		sum2 += num2*pow(10, length - 1 - i);
	}
	if (sum1 >= sum2) printf("%d\n", sum1);
	else printf("%d\n", sum2);
	return 0;
}