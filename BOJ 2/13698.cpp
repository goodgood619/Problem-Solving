#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char c[203];
int arr[5];
int main(){
	scanf("%s", c);
	int small = 1;
	int big = 4;
	int idx = 0;
	int idy = 0;
	for (int i = 1; i <= 4; i++) { arr[i] = i; }
	int length = strlen(c);
	for (int i = 0; i < length; i++) {
		if (c[i] == 'A') {
			int temp = arr[2];
			arr[2] = arr[1];
			arr[1] = temp;
		}
		else if (c[i] == 'B') {
			int temp = arr[3];
			arr[3] = arr[1];
			arr[1] = temp;
		}
		else if (c[i] == 'C') {
			int temp = arr[4];
			arr[4] = arr[1];
			arr[1] = temp;
		}
		else if (c[i] == 'D') {
			int temp = arr[2];
			arr[2] = arr[3];
			arr[3] = temp;
		}
		else if (c[i] == 'E') {
			int temp = arr[2];
			arr[2] = arr[4];
			arr[4] = temp;
		}
		else if (c[i] == 'F') {
			int temp = arr[3];
			arr[3] = arr[4];
			arr[4] = temp;
		}
	}
	for (int i = 1; i <= 4; i++) {
		if (arr[i] == small) {
			idx = i;
			continue;
		}
		else if (arr[i] == big) {
			idy = i;
			continue;
		}
	}
	printf("%d\n", idx);
	printf("%d\n", idy);
	return 0;
}