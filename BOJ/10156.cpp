#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a*b>c)
	printf("%d\n", ((a*b)-c));
	else if (a*b <= c) printf("0\n");
	return 0;
}