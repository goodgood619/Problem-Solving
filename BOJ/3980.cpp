#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t,ans;
int board[13][13];
bool visited[13];
void go(int index, int cnt,int hab){
	if (index > 12) return;
	if (cnt == 11) {
		ans = max(ans, hab);
		return;
	}
	for (int i = 1; i <= 11; i++){
		if (board[index][i] == 0) continue;
		if (!visited[i]){
			visited[i] = true;
			hab += board[index][i];
			go(index + 1, cnt + 1, hab);
			visited[i] = false;
			hab -= board[index][i];
		}
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		go(1,0,0);
		printf("%d\n", ans);
	}
	return 0;
}