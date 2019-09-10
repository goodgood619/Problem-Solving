#include <cstdio>
#include <algorithm>
using namespace std;
int n,idx;
int main(){
	scanf("%d", &n);
	n -= 1;
	for (int k = 1;; k++) {
		int total=(k*k) + k;
		if (total == n) {
			idx = k;
			break;
		}
	}
	printf("%d\n",idx);
	return 0;
}