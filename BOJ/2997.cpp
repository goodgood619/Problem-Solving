#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[3];
int main(){
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	sort(arr, arr + 3);
	int b = arr[1] - arr[0];
	int c = arr[2] - arr[1];
	if(b==c) printf("%d\n", arr[2] + b);
	else if(b>c){
		printf("%d\n", arr[0] + b / 2);
	}
	else if (b < c) {
		printf("%d\n", arr[1] + c / 2);
	}
	return 0;
}