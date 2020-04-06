#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <cstring>
using namespace std;
typedef int64_t ll;
int ans;
bool flag;
void change(int die,int* &penalty,int** &board, bool* &visited,int n) {
	for (int i = 0; i < n; i++) {
		if (die != i && !visited[i]) penalty[i] += board[die][i];
	}
}
void back(int die,int* &penalty, int** &board, bool* &visited,int n) {
	for (int i = 0; i < n; i++) {
		if (die != i && !visited[i]) penalty[i] -= board[die][i];
	}
}
bool check(int mafia, bool*& visited,int length) {
	for (int i = 0; i < length; i++) {
		if (visited[i] && mafia == i) return true;
	}
	return false;
}
void dfs(int time,int* &penalty, int** &board, bool* &visited, int ncnt,int rest,int mafia,int n) {
	if (flag) return;
	if (rest == 1 || check(mafia,visited,n)) {
		ans = max(ans, ncnt);
		if (rest == 1) {
			flag = true;
		}
		return;
	}

	// 밤(아무나 죽이자, 유죄배열을 변형시키고 다시 돌아왔을때 복구를 해줘야함)
	if (time == 1) {
		for (int i = 0; i < n; i++) {
			if (!visited[i] && mafia != i) {
				visited[i] = true;
				change(i, penalty, board, visited, n);
				dfs(0, penalty, board, visited, ncnt + 1, rest - 1, mafia,n);
				back(i, penalty, board, visited, n);
				visited[i] = false;
			}
		}
		if (flag) return;
	}
	else {
		int Max = 0;
		for (int i = 0; i <n; i++) {
			if (!visited[i]) {
				Max = max(Max, penalty[i]);
			}
		}
		int idx = 0;
		for (int i = 0; i < n; i++) {
			if (Max == penalty[i] && !visited[i]) {
				idx = i;
				break;
			}
		}
		visited[idx] = true;
		dfs(1, penalty, board, visited, ncnt, rest - 1, mafia,n);
		visited[idx] = false;
		if (flag) return;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int* penalty = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &penalty[i]);
	int** board = new int* [n];
	for (int i = 0; i < n; i++)  board[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	int mafia;
	scanf(" %d", &mafia);
	bool* visited = new bool[n];
	memset(visited, false, sizeof(visited));
	dfs(n % 2 == 0 ? 1 : 0, penalty, board, visited, 0, n, mafia,n);
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) delete[] board[i];
	delete[] board, visited,penalty;
	return 0;
}