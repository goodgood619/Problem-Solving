#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char a[100003];
char b[100003];
char an[100003];
char o[100003];
char xo[100003];
char nota[100003];
char notb[100003];
int main(){
	scanf("%s", a);
	scanf("%s", b);
	int length = strlen(a);
	for (int i = 0; i < length; i++) {
		int num1 = a[i] - '0';
		int num2 = b[i] - '0';
		if (num1 == 1 && num2 == 1) {
			an[i] = '1';
		}
		else an[i] = '0';

		if (num1 == 1 || num2 == 1) {
			o[i] = '1';
		}
		else o[i] = '0';

		if (num1 == 1 && num2 == 1) {
			xo[i] = '0';
		}
		else if (num1 == 0 && num2 == 0) {
			xo[i] = '0';
		}
		else xo[i] = '1';

		if (num1 == 1) {
			nota[i] = '0';
		}
		else nota[i] = '1';

		if (num2 == 1) {
			notb[i] = '0';
		}
		else notb[i] = '1';
	}
		printf("%s\n", an);
		printf("%s\n", o);
		printf("%s\n", xo);
		printf("%s\n", nota);
		printf("%s\n", notb);
	return 0;
}
