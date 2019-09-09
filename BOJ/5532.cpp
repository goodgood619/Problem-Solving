#include <stdio.h>
#include <algorithm>
using namespace std;
int L, a, b, c, d,cnt;
int main(){
	scanf("%d%d%d%d%d", &L, &a, &b, &c, &d);
	while (1) {
		int korea1=a / c;
		int korea2 = a%c;
		int math1 = b / d;
		int math2 = b%d;
		if (korea1 > math1) {
			cnt += korea1;
			if (korea2 != 0) {cnt += 1; break;
		}
			else break;
		}
		else if (korea1 < math1) {
			cnt += math1;
			if (math2 != 0) {cnt += 1; break;
		}
			else if (math2 == 0) break;
		}
		else if (korea1 == math1) {
			cnt += math1;
			if (korea2 == 0 && math2 == 0) break;
			else if (korea2 != 0 && math2 == 0) {
				cnt += 1; break;
			}
			else if (korea2 == 0 && math2 != 0) {
				cnt += 1; break;
			}
			else if (korea2 != 0 && math2 != 0) { cnt += 1; break; }
		}
	}
	printf("%d\n", L-cnt);
	return 0;
}