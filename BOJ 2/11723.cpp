#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int t;
int n = 1;
int main(){
	scanf("%d", &t);
	while (t--) {
		char c[15] = {'\0',};
		int num;
		scanf("%s", c);
		if (!strcmp(c, "add")) {
			scanf("%d", &num);
			n |= (1 << num);
		}
		else if (!strcmp(c, "remove")) {
			scanf("%d", &num);
			n=n&~(1 << num); // 이거 외우기 ㅇㅇ
		}
		else if (!strcmp(c, "check")) {
			scanf("%d", &num);
			if ((n&(1 << num)) == 0) printf("0\n");
			else if (n&(1 << num) == (1 << num)) printf("1\n");
		}
		else if (!strcmp(c, "toggle")) {
			scanf("%d", &num);
			n ^= (1 << num);
		}
		else if (!strcmp(c, "all")) {
			n = (1 << 21) - 1;
		}
		else if (!strcmp(c, "empty")) {
			n = 1;
		}
	}
	return 0;
}