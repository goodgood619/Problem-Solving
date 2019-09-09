#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <functional>
using namespace std;
int frien[105][105];
int target[105];
int score[105];
int n, m;
int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &target[i]);
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &frien[i][j]);
		}
	}

	int ptr = 1;
	for (int i = 1; i <= m; i++) {
		int firsttarget = target[i];
		int plus = 0;
		for (int j = 1; j <= n; j++) {
			if (firsttarget == frien[i][j]) {
				score[j]++;
			}
			else plus++;
		}
		score[firsttarget] += plus;
		ptr++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", score[i]);
	}
	return 0;
}