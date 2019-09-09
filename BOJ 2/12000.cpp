#include <cstdio>
#include <algorithm>
using namespace std;
int cow[2010];
int n;
int Min = 999999999;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cow[i]);
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		cow[i] = cow[i - n];
	}
	for (int i = 1; i <= n; i++){
		int cnt = 0;
		int sum = 0;
		for (int j = i;;j++){
			sum += cnt * cow[j];
			cnt++;
			if (cnt == n){
				Min = min(sum, Min);
				break;
			}
		}
	}
	printf("%d\n", Min);
	return 0;
}