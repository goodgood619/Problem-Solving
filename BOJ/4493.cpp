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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf(" %d", &n);
		int first = 0, second = 0;
		for (int i = 1; i <= n; i++) {
			char a, b;
			scanf(" %c %c", &a, &b);
			if (a == 'S' && b == 'P') first++;
			else if (a == 'S' && b == 'R') second++;
			else if (a == 'P' && b == 'S') second++;
			else if (a == 'P' && b == 'R') first++;
			else if (a == 'R' && b == 'S') first++;
			else if (a == 'R' && b == 'P') second++;
			else first++, second++;
		}
		if (first == second) printf("TIE\n");
		else if (first > second) printf("Player 1\n");
		else printf("Player 2\n");
	}
	return 0;
}