#include <cstdio>
#include <algorithm>
using namespace std;
int arr[3];
int main(){
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	int Max1 = arr[2] - arr[1];
	int Max2 = arr[1] - arr[0];
	if (Max1 < Max2) { printf("%d\n", Max2 - 1);}
	else printf("%d\n", Max1 - 1);
	return 0;
}