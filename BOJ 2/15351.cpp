
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int t;
char c[32];
int main() {
	scanf("%d", &t);
	getchar();
	while (t--){
		scanf("%[^\n]s", c);
		int length = strlen(c);
		int sum = 0;
		for (int i = 0; i < length; i++) {
			if (c[i] == ' ') continue;
			else {
				sum += (c[i] - 64);
			}
		}
		if (sum == 100) printf("PERFECT LIFE\n");
		else printf("%d\n", sum);
		getchar();
	}

	return 0;
}


