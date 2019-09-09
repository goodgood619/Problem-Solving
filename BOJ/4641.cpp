#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[20];
int main(){
	while (1) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &arr[1]);
		if (arr[1] == -1) break;
		else {
			int ptr = 2;
			for (;;){
				scanf("%d", &arr[ptr]);
				if (arr[ptr] == 0) break;
				ptr++;
			}
			int cnt = 0;
			for (int i = 1; i < ptr; i++) {
				for (int j = 1; j < ptr; j++) {
					if (arr[j] == arr[i] * 2) {
						cnt++;
						break;
					}
				}
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}