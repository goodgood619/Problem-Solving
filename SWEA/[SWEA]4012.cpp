#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;
int t,n;
int cnt = 1;
int Min = 99999999;
int board[19][19];
bool visited[19];
void go(int index, int ok,int cnt) {
	if (ok == cnt){
		vector <int> a;
		vector <int> b;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) a.push_back(i);
			else b.push_back(i);
		}
		int asum = 0;
		int bsum = 0;
		for (int i = 0; i < a.size(); i++) {
			for (int j = i+1; j < a.size(); j++){
				int num1 = a[i];
				int num2 = a[j];
				asum += (board[num1][num2] + board[num2][num1]);
			}
		}
		for (int i = 0; i < b.size(); i++) {
			for (int j = i + 1; j < b.size(); j++) {
				int num1 = b[i];
				int num2 = b[j];
				bsum += (board[num1][num2] + board[num2][num1]);
			}
		}
		Min = min(abs(asum - bsum), Min);
		return;
	}
	if (index > n) return;
	visited[index] = true;
	go(index + 1, ok + 1, cnt);
	visited[index] = false;
	go(index + 1, ok, cnt);
}
int main(){
	scanf("%d", &t);
	while (t--){
		Min = 99999999;
		memset(visited, false, sizeof(visited));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		go(1,0,n / 2);
		printf("#%d %d\n", cnt, Min);
		cnt++;
	}
	return 0;
}
