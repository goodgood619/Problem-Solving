#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int arr[103];
int main(){
	scanf("%d", &n);
	int a = 1;
	int b = 2;
	for (int i = 1; i <= n; i++){
		if (a < b) {
			arr[i] = a*b;
			a++;
		}
		else if (a == b) {
			arr[i] = a*b;
			b++;
		}
	}
	printf("%d\n", arr[n]);
	return 0;
}