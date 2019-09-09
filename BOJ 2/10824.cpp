#include <cstdio>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char a[10];
char b[10];
char c[10];
char d[10];
typedef long long ll;
int main(){
	scanf("%s%s%s%s", a, b, c, d);
	int aleng = strlen(a);
	int frontlength = strlen(b);
	int cleng = strlen(c);
	int backlength = strlen(d);
	ll frontsum = 0;
	ll backsum = 0;
	for (int i = 0; i < frontlength; i++) {
		frontsum += (b[i] - '0')*pow(10, frontlength - 1 - i);
	}
	for (int i = 0; i < aleng; i++) {
		frontsum += (a[i] - '0')*pow(10, aleng + frontlength - 1 - i);
	}
	for (int i = 0; i < backlength; i++) {
		backsum += (d[i] - '0')*pow(10, backlength - 1 - i);
	}
	for (int i = 0; i < cleng; i++) {
		backsum += (c[i] - '0')*pow(10, cleng + backlength - 1 - i);
	}
	printf("%lld\n", frontsum + backsum);
	return 0;
}