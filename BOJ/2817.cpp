#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int X, n,p;
int score[11][15];
typedef pair <char, int> P;
P player[10]; 
char c[2];
int s;
int fourteen[140];
int ans[14];
int main(){
	scanf("%d%d", &X,&n);
	fflush(stdin);
	for (int i =0; i <n; i++){
		scanf("%s%d", &c, &s);
		player[i].first = c[0];
		player[i].second = s;
		double a = X;
		double b = player[i].second;
		double d =b/a;
		if (d < 0.05){
			player[i].second = -1;
		}
	}
	sort(player, player + n);

	for (int i = 0; i < n; i++){
		if (player[i].second == -1) continue;
		for (int j = 1; j <= 14; j++) {
			score[i][j] = player[i].second/j;
			fourteen[p++]=score[i][j];
		}
	}
	sort(fourteen, fourteen + p);
	int Cnt = 0;
	for (int i = p-1;;i--){
		if (Cnt == 14) break;
		int cnt = fourteen[i];
		bool check = false;
		for (int j = 0; j < n; j++) {
			if (player[j].second == -1) continue;
			for (int k = 1; k <= 14; k++) {
				if (cnt == score[j][k]) {
					check = true;
					ans[j]++;
					break;
				}
			}
			if (check) break;
		}
		Cnt++;
	}
	for (int i = 0; i < n; i++){
		if (player[i].second == -1) continue;
		printf("%c %d\n", player[i].first, ans[i]);
	}
	return 0;
}