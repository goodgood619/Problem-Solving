#include <cstdio>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef long long ll;
char num[200];
int n;
ll sum;
int main(){
	scanf("%s%d", num, &n);
	int length = strlen(num);
	for (int i = length - 1; i >= 0; i--) {
		char c = num[i];
		int number;
		if (c >= 'A' && c <= 'Z') {
			number = c - 55;
		}
		else number = c - '0';
		sum +=(number*pow(n, length-1-i));
	}
	printf("%lld\n", sum);
	return 0;
}