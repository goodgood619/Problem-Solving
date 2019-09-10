#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[8] = { -1,1,0,0,1,1,-1,-1 };
int goy[8] = { 0,0,-1,1,-1,1,1,-1 };
int t, Case = 1, n, x;
int board[105][105];
int main() {
		scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		int cnt = 0;
		//행
		for (int i = 1; i <= n; i++) {
			int firstheight = board[i][1];
			int same = 0;
			int no = 0;
			int up = 0, down = 0;
			for (int j = 1; j <= n; j++) {
				if (abs(firstheight - board[i][j]) >= 2) {
					no = 1;
					break;
				}
				if (firstheight == board[i][j]) {
					same++;
					if (j == n) {
						if (same < x && down == 1) {
							no = 1;
							break;
						}
					}
					continue;
				}
				else if (firstheight < board[i][j]) { //더 높아지는 경우
					if (up == 0 && down == 0) { //최초의 변화되는 상태
						if (same < x) {
							no = 1;
							break;
						}
						up = 1, same = 1, firstheight = board[i][j];
					}
					else if (up == 1 && down == 0) { //연속으로 높아지는 경우
						if (same < x) {
							no = 1;
							break;
						}
						up = 1, same = 1, firstheight = board[i][j];
					}
					else if (up == 0 && down == 1) { //이전상태가 낮았던 경우(c의경우)
						if (same >= x && same < 2 * x || same < x) {
							no = 1;
							break;
						}
						up = 1, down = 0, firstheight = board[i][j];
					}
				}
				else { //더 낮아지는 경우
					if (up == 1 && down == 0) { //이전상태가 높았던 경우
						same = 1, up = 0, down = 1, firstheight = board[i][j];
					}
					else if (up == 0 && down == 0) { //최초 변화 상태(처음으로 낮아짐
						same = 1, down = 1, firstheight = board[i][j];
					}
					else if (up == 0 && down == 1) { //연속으로 낮아질때
						if (same < x) {
							no = 1;
							break;
						}
						down = 1, same = 1, firstheight = board[i][j];
					}
					if (j == n) {
						if (same < x) {
							no = 1;
							break;
						}
					}
				}
			}
			if (!no) cnt++;
		}
		//열
		for (int j = 1; j <= n; j++) {
			int firstheight = board[1][j];
			int same = 0;
			int no = 0, up = 0, down = 0;
			for (int i = 1; i <= n; i++) {
				if (abs(firstheight - board[i][j]) >= 2) {
					no = 1;
					break;
				}
				if (firstheight == board[i][j]) {
					same++;
					if (i == n && down == 1) {
						if (same < x) {
							no = 1;
							break;
						}
					}
					continue;
				}
				else if (firstheight < board[i][j]) { //더 높아지는 경우
					if (up == 0 && down == 0) { //최초의 변화되는 상태
						if (same < x) {
							no = 1;
							break;
						}
						up = 1, same = 1, firstheight = board[i][j];
					}
					else if (up == 1 && down == 0) { //연속으로 높아지는 경우
						if (same < x) {
							no = 1;
							break;
						}
						up = 1, same = 1, firstheight = board[i][j];
					}
					else if (up == 0 && down == 1) { //이전상태가 낮았던 경우
						if (same >= x && same < 2 * x || same < x) {
							no = 1;
							break;
						}
						up = 1, down = 0, same = 1, firstheight = board[i][j];
					}
				}
				else { //더 낮아지는 경우
					if (up == 1 && down == 0) { //이전상태가 높았던 경우
						same = 1, up = 0, down = 1, firstheight = board[i][j];
					}
					else if (up == 0 && down == 0) { //최초 변화 상태(처음으로 낮아짐
						same = 1, down = 1, firstheight = board[i][j];
					}
					else if (up == 0 && down == 1) { //연속으로 낮아질때
						if (same < x) {
							no = 1;
							break;
						}
						down = 1, same = 1, firstheight = board[i][j];
					}
					if (i == n) {
						if (same < x) {
							no = 1;
							break;
						}
					}
				}
			}
			if (!no) cnt++;
		}
			printf("%d\n", cnt);
	return 0;
}