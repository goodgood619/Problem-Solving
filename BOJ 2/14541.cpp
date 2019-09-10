#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
	while (1){
		scanf("%d", &n);
		if (n == -1) break;
		else {
			int sum = 0;
			int first, mile;
			scanf("%d%d", &first, &mile);
			sum += first*mile;
			for (int i = 2; i <= n; i++) {
				int second, mile2;
				scanf("%d%d", &second, &mile2);
				sum += second*(mile2 - mile);
				mile = mile2;
			}
			printf("%d miles\n", sum);
		}
	}
	return 0;
}