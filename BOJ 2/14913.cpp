#include <cstdio>
#include <algorithm>
using namespace std;
int a, d, k,ans;
int arr[1100003];
int main(){
	scanf("%d%d%d", &a, &d, &k);
	arr[1] = a;
	bool check = false;
	if (a == k) printf("1\n");
	else {
		for (int i = 2;; i++) {
			arr[i] = a + (i - 1)*d;
			if (arr[i] >= 1000000 || arr[i] <= -1000000) {
				check = true;
				break;
			}
			if (arr[i] == k) {
				ans = i;
				break;
			}
		}
		if (check) printf("X\n");
		else printf("%d\n", ans);
	}
 	return 0;
}