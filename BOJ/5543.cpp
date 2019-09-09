#include <stdio.h>
#include <algorithm>
using namespace std;
int burger[3];
int drinks[2];
int ans = 100000;
int main() {
	for (int i = 0; i < 3; i++)
		scanf("%d", &burger[i]);
	for (int i = 0; i < 2; i++)
		scanf("%d", &drinks[i]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			ans = min(ans, burger[i] + drinks[j] - 50);
		}
	}
	printf("%d\n", ans);
	return 0;
}