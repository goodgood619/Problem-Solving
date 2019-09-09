#include <cstdio>
#include <algorithm>
using namespace std;
int t,n;
int main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		double arr[1005] = { 0, };
		double sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lf", &arr[i]);
			sum += arr[i];
		}
		sum /= n;
		double ok = 0;
		double ahr = n;
		for (int i = 1; i <= n; i++) {
			if (sum < arr[i]) ok++;
			else continue;
		}
		char c = '%';
		printf("%.3lf%c\n",(ok /ahr)*100,c);

	}
	return 0;
}