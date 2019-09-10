#include <cstdio>
#include <algorithm>
using namespace std;
int team1[303];
int team2[303];
int cnt, Max;
bool check;
// 1: 가위
// 2:바위
// 3: 보
// 비기는 경우는 턴이 바뀜 ㅇㅇ
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &team1[i]); }
	for (int i = 1; i <= n; i++) { scanf("%d", &team2[i]); }
	if ((team1[1] == 1 && team2[1] == 3) || (team1[1] == 2 && team2[1] == 1) || (team1[1] == 3 && team2[1] == 2)) {
		check = false;
		cnt++;
	}
	else {
		check = true;
		cnt++;
	}
	Max = max(Max, cnt);
	for (int i = 2; i <= n; i++) {
		int what1 = team1[i];
		int what2 = team2[i];
		if (what1 == 1 && what2 == 3) {
			if (!check) cnt++;
			else cnt = 1;
			check = false;
		}
		else if (what1 == 2 && what2 == 1) {
			if (!check) cnt++;
			else cnt = 1;
			check = false;
		}
		else if (what1 == 3 && what2 == 2) {
			if (!check) cnt++;
			else cnt = 1;
			check = false;
		}
		else if (what1 == 3 && what2 == 1) {
			if (check) cnt++;
			else cnt = 1;
			check = true;
		}
		else if (what1 == 1 && what2 == 2) {
			if (check) cnt++;
			else cnt = 1;
			check = true;
		}
		else if (what1 == 2 && what2 == 3) {
			if (check) cnt++;
			else cnt = 1;
			check = true;
		}
		else if (what1 == what2) {
			if (!check) check = true;
			else check = false;
			cnt = 1;
		}
		Max = max(Max, cnt);
	}
	printf("%d\n", Max);
	return 0;
}