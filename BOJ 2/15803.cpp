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
int t;
P position[4];
int main() {
	for (int i = 1; i <= 3; i++) {
		scanf("%d%d", &position[i].first, &position[i].second);
	}
	sort(position + 1, position + 4);
	int a1 = position[2].first - position[1].first;
	int a2 = position[2].second - position[1].second;
	int a3 = position[3].first - position[1].first;
	int a4 = position[3].second - position[1].second;
	if ((a1 == 0 && a3 == 0) || (a2 == 0 && a4 == 0)) printf("WHERE IS MY CHICKEN?\n");
	else if (double(a1) / a3 == double(a2) / a4) printf("WHERE IS MY CHICKEN?\n");
	else printf("WINNER WINNER CHICKEN DINNER!\n");
	return 0;
}