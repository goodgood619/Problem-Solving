#include <cstdio>
#include <algorithm>
using namespace std;
int a, b;
int main(){
	scanf("%d", &a);
	scanf("%d", &b);
	int gob = a*b;
	printf("%d\n", a*(b % 10));
	printf("%d\n", a*((b / 10) % 10));
	printf("%d\n", a*(b/100));
	printf("%d\n", gob);
	return 0;
}