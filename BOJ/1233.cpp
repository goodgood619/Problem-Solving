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
int a, b, c;
int cnt[85];
int main() {
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				cnt[i + j + k]++;
			}
		}
	}

	int Max = 0;
	int ans = 0;
	for (int i = 1; i <= 80; i++) {
		if (Max < cnt[i]) {
			Max = cnt[i];
			ans = i;
		}
	}
	printf("%d\n",ans);
	return 0;
}