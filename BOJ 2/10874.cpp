#include <cstdio>
#include <algorithm>
using namespace std;
int arr[105][12];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			int num;
			scanf("%d", &num);
			arr[i][j] = num;
		}
	}
	for (int i = 1; i <= n; i++) {
		int ok = 0;
		int start = 1;
		for (int j = 1; j <= 10; j++){
			if (start == arr[i][j]) {
				start++;
				ok++;
				if (start == 6) start = 1;
				continue;
			}
			else break;
		}
		if (ok != 10) continue;
		else printf("%d\n", i);
	}
	return 0;
}