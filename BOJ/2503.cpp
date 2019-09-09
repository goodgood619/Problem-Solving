#include <stdio.h>
#include <algorithm>
using namespace std;
int n,num,strike,ball,cnt;
int Number[1000];
int Cnt[1000];
bool ok[1000];
void go(int Number, int real, int strike, int ball) {
	int N1 = Number / 100;
	int N2 = Number / 10 % 10;
	int N3 = Number % 10;
	int r1 = real / 100;
	int r2 = real / 10 % 10;
	int r3 = real % 10;
	int stcnt = 0;
	int bcnt = 0;
	if (N1 == 0 || N2 == 0 || N3 == 0 || N1 == N2 || N2 == N3 || N3 == N1) return;
	if (N1 == r1) stcnt++;
	if (N2 == r2) stcnt++;
	if (N3 == r3) stcnt++;

	if (N1 == r2 || N1 == r3) bcnt++;
	if (N2 == r1 || N2 == r3) bcnt++;
	if (N3 == r1 || N3 == r2) bcnt++;
	//정답
	if (strike == stcnt && ball == bcnt) {
		ok[Number] = true; Cnt[Number]++;
	}
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d",&num,&strike,&ball);
		for (int i = 123; i <= 987; i++) {
				go(i, num, strike, ball);
		}
	}

	for (int i = 123; i <= 987; i++) {
		if (Cnt[i]==n) cnt++;
		else continue;
	}
	printf("%d\n", cnt);
	return 0;
}