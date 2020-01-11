#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		char c;
		scanf(" %d %c", &n, &c);
		if (c == 'C') {
			for (int i = 0; i < n; i++) {
				char cc;
				scanf(" %c", &cc);
				printf("%d ", cc - 'A' + 1);
			}
			printf("\n");
		}
		else {
			for (int i = 0; i < n; i++) {
				int num;
				scanf(" %d", &num);
				printf("%c ", num + 'A' - 1);
			}
			printf("\n");
		}
	}
	return 0;
}