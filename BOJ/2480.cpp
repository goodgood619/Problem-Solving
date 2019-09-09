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
int cnt[7];
int main() {
	int Max = 0;
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		int num;
		scanf("%d", &num);
		cnt[num]++;
		if (Max < cnt[num]) {
			Max = cnt[num];
			idx = num;
		}
	}
	if (Max == 3) {
		printf("%d\n", 10000 + idx * 1000);
	}
	else if (Max == 2) {
		printf("%d\n", 1000 + idx * 100);
	}
	else {
		int a = 0;
		for (int i = 1; i <= 6; i++) {
			if (Max == cnt[i]) {
				a = max(a, i);
			}
		}
		printf("%d\n", a * 100);
	}
	return 0;
}