#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	if (n % 2 == 0) printf("CY\n");
	else printf("SK\n");
	return 0;
}