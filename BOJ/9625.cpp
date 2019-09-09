#include <stdio.h>
#include <algorithm>
using namespace std;
int cntA[46];
int cntB[46];
int k;
int main(){
	scanf("%d", &k);
	cntA[0] = 1;
	cntB[0] = 0;
	for (int i = 0; i < k; i++) {
		cntA[i+1] = cntB[i];
		cntB[i + 1] = cntB[i]+ cntA[i];
	}
	printf("%d %d\n", cntA[k], cntB[k]);
	return 0;
}