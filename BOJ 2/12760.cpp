#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int arr[101];
int real[101][101];
int score[101];
int answer[101];
int k;
int Max;
int winscore;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <m; j++) {
			scanf("%d", &arr[j]);
		}
		sort(arr, arr + m);
		for (int j = 0; j <m; j++) {
			real[k][j] = arr[j];
		}
		k++;
	}
	for (int j = m-1; j >= 0; j--) {
		for (int i = 0; i <n; i++) {
			Max = max(real[i][j], Max);
		}
		for (int i = 0; i < n; i++) {
			if (real[i][j] == Max)
				score[i]++;
			winscore = max(score[i], winscore);
		}
		Max = 0;
	}
	for (int i = 0; i < n; i++) {
		if (winscore == score[i])
			printf("%d ", i+1);
	}
	return 0;
}