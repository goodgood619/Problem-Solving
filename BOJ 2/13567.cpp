#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int board[1005][1005];
int n, m,stx,sty,rota;
typedef pair <string, int> P;
P question[1005];
// 0:동 1:남 2:서 3:북(x값증가)
int gox[4] = {0,-1,0,1};
int goy[4] = {1,0,-1,0};
bool check;
int turn(int rota, int move) {
	if (move == 0) {
		rota -= 1;
		if (rota < 0) return 3;
		else return rota;
	}
	else if (move == 1) {
		rota = (rota + 1) % 4;
		return rota;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		char s[10] = { '\0', };
		int what;
		scanf("%s%d", s, &what);
		question[i].first = s;
		question[i].second = what;
	}
	int herex = stx;
	int herey = sty;
	for (int i = 1; i <= m; i++){
		if (herex<0 || herex>n - 1 || herey<0 || herey>n - 1){
			check = true;
			break;
		}
		string s = question[i].first;
		int move = question[i].second;
		if (s == "MOVE") {
			herex = herex + move*gox[rota];
			herey = herey + move*goy[rota];
		}
		else if (s == "TURN") {
			rota=turn(rota, move);
		}
	}
	if (herex<0 || herex>n - 1 || herey<0 || herey>n - 1) { check = true; }
	if (check) printf("-1\n");
	else printf("%d %d\n", herey, herex);
	return 0;
}