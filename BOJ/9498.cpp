#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	if (n <= 100 && n >= 90) printf("A\n");
	else if (n <= 89 && n >= 80) printf("B\n");
	else if (n <= 79 && n >= 70) printf("C\n");
	else if (n <= 69 && n >= 60) printf("D\n");
	else printf("F\n");
	return 0;
}