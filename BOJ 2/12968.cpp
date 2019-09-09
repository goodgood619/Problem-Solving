#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int r, c, k;
int main() {
	scanf("%d%d%d", &r, &c, &k);
	if (r % 2 == 0 && c % 2 == 0) printf("1\n");
	else if (r % 2 == 0  && c % 2 == 1) printf("1\n"); // 무조건 2면 가능
	else if (c % 2 == 0 && r % 2 == 1) printf("1\n");
	else if (k == 1) printf("1\n");
	else printf("0\n");
	return 0;
}