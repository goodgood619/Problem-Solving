#include <stdio.h>
#include <algorithm>
using namespace std;
int day[366];
int x, y;
int cnt;
int main() {
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= 365; i++) {
		if (i % 7 == 1)
			day[i] = 1;
		else if (i % 7 == 2)
			day[i] = 2;
		else if (i % 7 == 3)
			day[i] = 3;
		else if (i % 7 == 4)
			day[i] = 4;
		else if (i % 7 == 5)
			day[i] = 5;
		else if (i % 7 == 6)
			day[i] = 6;
		else if (i % 7 == 0)
			day[i] = 7;
	}
	for (; x >1;) {
		if (x == 2)
		{
			cnt += 31;
			x--;
		}
		else if (x == 3) {
			cnt += 28;
			x--;
		}
		else if (x == 4) {
			cnt += 31;
			x--;
		}
		else if (x == 5) {
			cnt += 30;
			x--;
		}
		else if (x == 6) {
			cnt += 31;
			x--;
		}
		else if (x == 7) {
			cnt += 30;
			x--;
		}
		else if (x == 8) {
			cnt += 31;
			x--;
		}
		else if (x == 9) {
			cnt += 31;
			x--;
		}
		else if (x == 10) {
			cnt += 30;
			x--;
		}
		else if (x == 11) {
			cnt += 31;
			x--;
		}
		else if (x == 12) {
			cnt += 30;
			x--;
		}
	}
	cnt += y;
	if (cnt % 7 == 1)
		printf("MON\n");
		else if (cnt % 7 == 2)
			printf("TUE\n");
		else if (cnt % 7 == 3)
			printf("WED\n");
		else if (cnt %7 == 4)
			printf("THU\n");
		else if (cnt% 7 == 5)
			printf("FRI\n");
		else if (cnt % 7 == 6)
			printf("SAT\n");
		else if (cnt% 7 == 0)
			printf("SUN\n");
	return 0;
}