#include <cstdio>
#include <algorithm>
using namespace std;
int broken, cnt;
long long total;
int main() {
	scanf("%d", &broken);
	scanf("%d", &cnt);
	if (broken == 1 && cnt == 0) printf("0\n");
	else {
		if (cnt >= 1) {
			if (broken >= 2 && broken <= 4) {
				if (cnt % 2 == 0) {
					long long ahr = cnt / 2;
					total = total + 5 + (4 * (2 *ahr-1));
					for (int i = 2; i <= broken; i++) {
						if (i == broken) break;
						total++;
					}
					printf("%lld\n", total);
				}
				else if ((cnt - 1) % 2 == 0) {
					int ahr = (cnt - 1) / 2;
					total = total + 5 + (4 * 2 * ahr);
					for (int i = 4; i >= 1; i--) {
						if (broken == i) break;
						total++;
					}
					printf("%lld\n", total);
				}
			}
			else if (broken == 1) {
				long long ahr = cnt - 1;
				total = total + 5 + (4 * 2 * ahr);
				total += 3;
				printf("%lld\n", total);
			}
			else if (broken == 5) {
				long long ahr = cnt - 1;
				total = total + 5 + (4 * 2 * ahr);
				total += 7;
				printf("%lld\n", total);
			}
		}
		else {
			printf("%d\n", broken - 1);
		}
	}
	return 0;
}