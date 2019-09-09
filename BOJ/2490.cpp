#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[3][4];
int zero, one;
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) zero++;
		}
		if (zero == 0) {
			printf("E\n");
		}
		else if (zero == 1) {
			printf("A\n");
		}
		else if (zero == 2) {
			printf("B\n");
		}
		else if (zero == 3) {
			printf("C\n");
		}
		else if (zero == 4) {
			printf("D\n");
		}
		zero = 0;
	}
	return 0;
}