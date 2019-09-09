#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int cnt = 1;
int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		int n1 = n * 3;
		int n2 = 0;
		char what[7] = { '\0', };
		bool check = false;
		if (n1 % 2 == 0){
			check = false;
			n2 = n1 / 2;
		}
		else {
			check = true;
			n2=(n1 + 1) / 2;
		}
		int n3 = 3 * n2;
		int n4 = n3 / 9;
		if (check) strcpy(what, "odd");
		else strcpy(what, "even");
		printf("%d. %s %d\n", cnt,what,n4);
		cnt++;
	}
	return 0;
}