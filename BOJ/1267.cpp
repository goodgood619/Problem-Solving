#include <stdio.h>
#include <algorithm>
using namespace std;
int n,Y,M,ahrt,ahrt2;
int arr[20];
int main(){
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]);}
	for (int i = 0; i < n; i++){
		if (arr[i] == 0) continue;
		 ahrt = arr[i] / 30;
		 ahrt2 = arr[i] / 60;
		Y=Y+(ahrt+1) * 10;
		M=M+(ahrt2+1) * 15;
	}
	if (Y < M) { printf("Y %d\n",Y);}
	else if (Y > M) { printf("M %d\n",M);}
	else if (Y == M) { printf("Y M %d\n",Y);}
	return 0;
}