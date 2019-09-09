#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[102];
int n,zero,one;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); }
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) zero++;
		else one++;
	}
	if (zero > one)printf("Junhee is not cute!");
	else if (zero < one)printf("Junhee is cute!");
	return 0;
}