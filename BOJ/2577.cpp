#include <stdio.h>
#include <algorithm>
using namespace std;
int a, b, c;
long long d;
int arr[10];
int main() {
	scanf("%d%d%d", &a, &b, &c);
	d = a*b*c;
	for (; d >0;) {
		int cnt = d % 10;
		if (cnt == 0) arr[0]++;
		else if (cnt == 1) arr[1]++;
		else if (cnt == 2) arr[2]++;
		else if (cnt == 3) arr[3]++;
		else if (cnt == 4) arr[4]++;
		else if (cnt == 5) arr[5]++;
		else if (cnt == 6) arr[6]++;
		else if (cnt == 7) arr[7]++;
		else if (cnt == 8) arr[8]++;
		else if (cnt == 9) arr[9]++;
		d = d / 10;
	}
	for (int i = 0; i <= 9; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}