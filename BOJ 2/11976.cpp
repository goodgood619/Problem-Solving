#include <cstdio>
#include <algorithm>
using namespace std;
int ba, bb, sa, sb, ga, gb, pa, pb;
int main(){
	scanf("%d%d", &ba, &bb);
	scanf("%d%d", &sa, &sb);
	scanf("%d%d", &ga, &gb);
	scanf("%d%d", &pa, &pb);
	int b=gb-ga+pb - pa;
	int c=sb-sa+ (gb - ga)+pb-pa;
	printf("%d\n", c);
	printf("%d\n", b);
	printf("%d\n", pb - pa);
	return 0;
}
