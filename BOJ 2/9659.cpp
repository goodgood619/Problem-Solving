#include <stdio.h>
#include <algorithm>
using namespace std;
long long n;
int main(){
	scanf("%lld", &n);
	if (n % 2 == 0) printf("CY\n");
	else printf("SK\n");
	return 0;
}