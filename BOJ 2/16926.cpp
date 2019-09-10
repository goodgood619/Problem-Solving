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
#define mod 1000000009
#define lim 1000000000
typedef pair <int, int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,-1,1,1,-1 };
int n, m, r;
int board[305][305];
deque<int> d[180];
int main(void) {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	int p = n, q = m;
	int sx = 1, sy = 1,ptr=1;
	while (1) {
		if (p < 2 || q < 2) break;
		int ex = sx + p - 1, ey = sy + q - 1;
		for (int i = 0; i < p; i++) {
			d[ptr].push_back(board[sx+i][sy]);
		}
		d[ptr].pop_back();
		for (int i = 0; i < q; i++) {
			d[ptr].push_back(board[ex][sy + i]);
		}
		d[ptr].pop_back();
		for (int i = 0; i < p; i++) {
			d[ptr].push_back(board[ex-i][ey]);
		}
		d[ptr].pop_back();
		for (int i = 0; i < q; i++) {
			d[ptr].push_back(board[sx][ey - i]);
		}
		d[ptr].pop_back();
		p -= 2, q -= 2,sx++,sy++,ptr++;
	}
	for (int i = 1; i <= r; i++) {
		for (int i = 1; i < ptr; i++) {
			d[i].push_front(d[i].back());
			d[i].pop_back();
		}
	}
	p = n, q = m;
	sx = 1, sy = 1, ptr = 1;
	while (1) {
		if (p < 2 || q < 2) break;
		int ex = sx + p - 1, ey = sy + q - 1,num=-1;
		for (int i = 0; i < p; i++) {
			board[sx+i][sy] = d[ptr].front();
			num = d[ptr].front();
			d[ptr].pop_front();
		}
		d[ptr].push_front(num);
		for (int i = 0; i < q; i++) {
			board[ex][sy + i] = d[ptr].front();
			num = d[ptr].front();
			d[ptr].pop_front();
		}
		d[ptr].push_front(num);
		for (int i = 0; i < p; i++) {
			
			board[ex - i][ey] = d[ptr].front();
			num = d[ptr].front();
			d[ptr].pop_front();
		}
		d[ptr].push_front(num);
		for (int i = 0; i < q-1; i++) {
			
			board[sx][ey - i] = d[ptr].front();
			num = d[ptr].front();
			d[ptr].pop_front();
		}
		p -= 2, q -= 2, sx++, sy++, ptr++;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}