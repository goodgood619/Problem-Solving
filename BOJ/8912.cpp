#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
int sales[1005];
int temp[1005];
int main() {
	scanf("%d", &t);
	while (t--){
		memset(sales, 0, sizeof(sales));
		memset(temp, 0, sizeof(temp));
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++) { scanf("%d", &sales[i]);}
		for (int i = 2; i <= n; i++){
			int cnt = 0;
			for (int j = 1; j < i; j++) {
				if (sales[j] <= sales[i]) cnt++;
				else continue;
			}
			temp[i] = cnt;
			sum += cnt;
		}
		printf("%d\n", sum);
	}
	return 0;
}