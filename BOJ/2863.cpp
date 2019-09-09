#include <stdio.h>
#include <algorithm>
using namespace std;
double chart[2][2];
int main() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf(" %lf", &chart[i][j]);
		}
	}
	double Max = 0;
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		if (Max < (chart[0][0] / chart[1][0]) + (chart[0][1] / chart[1][1])) {
			idx = i;
			Max = (chart[0][0] / chart[1][0]) + (chart[0][1] / chart[1][1]);
		}
		double temp = chart[0][0];
		chart[0][0] = chart[1][0];
		chart[1][0] = chart[1][1];
		chart[1][1] = chart[0][1];
		chart[0][1] = temp;
	}
	printf("%d\n", idx);
	return 0;
}
