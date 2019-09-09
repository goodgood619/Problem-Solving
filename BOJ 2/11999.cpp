#include <cstdio>
#include <algorithm>
using namespace std;
int a, b, c,xcnt,ycnt,Max;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	while (a*xcnt<=c){
		int sum = 0;
		for (int i = 0; sum <= c; i++){
			sum = a * xcnt + b * i;
			if (sum <= c) {
				Max = max(Max, sum);
			}
		}
		xcnt++;
	}
	printf("%d\n", Max);
	return 0;
}