#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
typedef pair<int, pair<int, int>> P;
P team[10005];
int ans[103][103]; // 제출횟수용
int score[103][103]; //특정문제의 최종점수
int ti[103][103]; //각 팀마다 제출시간
int total[103]; // 총점
int cnt[103]; //각팀의 총 제출횟수
int lasti[103]; //마지막 제출시간
int board[103]; // 최종 순위
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(ans, 0, sizeof(ans));
		memset(team, 0, sizeof(team));
		memset(score, 0, sizeof(score));
		memset(ti, 0, sizeof(ti));
		memset(total, 0, sizeof(total));
		memset(cnt, 0, sizeof(cnt));
		memset(lasti, 0, sizeof(lasti));
		memset(board, 0, sizeof(board));
		int n, k, t, m;
		scanf("%d%d%d%d", &n, &k, &t, &m);
		int myteam = t;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &team[i].first, &team[i].second.first, &team[i].second.second);
		}
		for (int i = 1; i <= n; i++) {
			int teamid = i;
			for (int j = 1; j <= m; j++) {
				if (teamid != team[j].first) continue;
				else if (teamid == team[j].first) {
					int problem = team[j].second.first;
					int earn = team[j].second.second;
					score[teamid][problem] = max(score[teamid][problem], earn);
					ans[teamid][problem]++;
					ti[teamid][problem] = j;
				}
			}
		}
		// 총합점수
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			int totalcnt = 0;
			int tiMax = 0;
			for (int j = 1; j <= k; j++) {
				sum += score[i][j];
				totalcnt += ans[i][j];
				tiMax = max(tiMax, ti[i][j]);
			}
			total[i] = sum;
			cnt[i] = totalcnt;
			lasti[i] = tiMax;
		}
		
		for (int i = 1; i <= n; i++){
			int win = 0;
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				else {
					if (total[i] > total[j]) { win++;
					continue;
					}
					else if (total[i] == total[j] && cnt[i] < cnt[j]) {
						win++;
						continue;
					}
					else if (total[i] == total[j] && cnt[i] == cnt[j] && lasti[i] < lasti[j]) {
						win++;
						continue;
					}
					else continue;
				}
			}
			board[i] = n - win;
		}
		printf("%d\n", board[myteam]);
	}
	return 0;
}