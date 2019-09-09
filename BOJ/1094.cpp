#include <cstdio>
#include <algorithm>
using namespace std;
int n,cnt;
int arr[7] = {64,32,16,8,4,2,1};
int main(){
	scanf("%d", &n);
	int p = n;
	while (p != 0) {
		for (int i = 0; i < 7; i++) {
			if (p < arr[i]) continue;
			else {
				p -= arr[i];
				cnt++;
				break;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}