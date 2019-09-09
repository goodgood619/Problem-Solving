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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, r, c;
void go(int n, int r, int c, int cnt) {
	if (r == 0 && c == 0) {
		printf("%d\n", cnt);
		exit(0);
	}
	int length = pow(2, n - 1);
	if (r < length && c < length) go(n - 1, r, c, cnt);
	if (r < length && c >= length) go(n - 1, r, c - length, cnt + length * length);
	if (r >= length && c < length) go(n - 1, r - length, c, cnt + length * length * 2);
	if (r >= length && c >= length) go(n - 1, r - length, c - length, cnt + length * length * 3);
}
int main() {
	scanf("%d%d%d", &n, &r, &c);
	go(n, r, c,0);
	return 0;
}