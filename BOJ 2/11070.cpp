#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int winscore[1005];
int losescore[1005];
int main(){
	scanf("%d", &t);
	while (t--) {
		int n, m;
		memset(winscore, 0, sizeof(winscore));
		memset(losescore, 0, sizeof(winscore));
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int first, second, score1, score2;
			scanf("%d%d%d%d", &first, &second, &score1, &score2);
			winscore[first] += score1;
			winscore[second] += score2;
			losescore[first] += score2;
			losescore[second] += score1;
		}
		int Min = 9999999;
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			int win = winscore[i];
			int lose = losescore[i];
			if (win == 0 && lose == 0) {
				Min = min(Min, 0);
				Max = max(Max, 0);
			}
			else {
				win *= win;
				lose *= lose;
				double pita = (double)win / (win + lose);
				pita *= 1000;
				int ok = (int)pita;
				Min = min(Min, ok);
				Max = max(Max, ok);
			}
		}
		printf("%d\n", Max);
		printf("%d\n", Min);
	}
	return 0;
}