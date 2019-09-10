#include<cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char name[23];
int main() {
	scanf("%s", name);
	for (int i = 0; i < 3; i++){
		if (i != 1) {
			for (int j = 0; j < 3; j++) {
				printf(":fan:");
			}
			printf("\n");
		}
		else {
			printf(":fan:");
			printf(":%s:", name);
			printf(":fan:");
			printf("\n");
		}
	}
	return 0;
}