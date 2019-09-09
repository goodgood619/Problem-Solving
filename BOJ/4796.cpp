#include <stdio.h>
#include <algorithm>
using namespace std;
int L, P, V;
int k = 1;
int main(){
	while (1) {
		scanf("%d%d%d", &L, &P, &V);
		int sum = 0;
		if (L == 0 && P == 0 && V == 0) break;
		while (V != 0) {
			if (V > P) {
				sum += L;
				V -= P;
			}
			else {
				if (V < L) {
					sum += V;
					V -= V;
				}
				else {
					sum += L;
					V -= V;
				}
			}
		}
		printf("Case %d: %d\n",k, sum);
		k++;
	}
	return 0;
}