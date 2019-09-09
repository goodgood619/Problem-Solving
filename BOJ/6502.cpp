#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;

int main(){
	double a, b, c;
	int cnt = 1;
	while (1) {
		scanf("%lf", &a);
		if (a == 0) break;
		else{
			scanf("%lf%lf", &b, &c);
			if (a>= sqrt((b / 2)*(b / 2) + (c / 2)*(c / 2))) {
				printf("Pizza %d fits on the table.\n", cnt);
			}
			else {
				printf("Pizza %d does not fit on the table.\n", cnt);
			}
		}
		cnt++;
	}
	return 0;
}