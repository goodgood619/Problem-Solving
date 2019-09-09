#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char a[10005];
char b[10005];
int main(){
	scanf("%s%s", a, b);
	int length1 = strlen(a);
	int length2 = strlen(b);
	long long total = 0;
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			total += (a[i] - '0')*(b[j] - '0');
		}
	}
	printf("%lld\n", total);
	return 0;
}