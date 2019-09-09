#include <cstdio>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
int n;
void go(int newhour, int newminute) {
	if (newhour <= 9 && newminute <= 9) printf("0%d:0%d\n", newhour, newminute);
	else if (newhour <= 9 && newminute >= 10 && newminute <= 59) printf("0%d:%d\n", newhour, newminute);
	else if (newhour >= 10 && newminute <= 9) printf("%d:0%d\n", newhour, newminute);
	else if (newhour >= 10 && newminute >= 10 && newminute <= 59) printf("%d:%d\n", newhour, newminute);
}
int main(){
	scanf("%d", &n);
	int curhour, curminute;
	double curutc;
	scanf("%d:%d ", &curhour, &curminute);
	scanf("UTC %lf",&curutc);
	for (int i = 1; i <= n; i++){
		double whatcur;
		scanf(" UTC %lf", &whatcur);
		double diff = whatcur-curutc;
		if (diff == 0) {
			go(curhour, curminute);
			continue;
		}
		int newhour = curhour + (int)diff;
		int newminute = curminute;
		double sk = diff - (int)diff;
		if (sk > 0) {
			newminute = curminute + 30;
			if (newminute >= 60) {
				newminute %= 60;
				newhour += 1;
			}
		}
		else if (sk < 0){
			newminute = curminute - 30;
			if (newminute < 0) {
				newminute += 60;
				newhour -= 1;
			}
		}
		if (newhour < 0) newhour += 24;
		if (newhour >= 24) newhour %= 24;
		go(newhour, newminute);
	}
	return 0;
}