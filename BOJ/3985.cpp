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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int l,n;
int roll[1005];
int who[1005];
int main() {
	scanf("%d", &l);
	scanf("%d", &n);
	int expect = 0;
	int real = 0;
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (Max < second - first) {
			Max = second - first;
			expect = i;
		}
		for (int j = first; j <= second; j++) {
			if (roll[j] != 0) continue;
			else roll[j] = i;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		if (roll[i] == 0) continue;
		else who[roll[i]]++;
	}
	Max = 0;
	for (int i = 1; i <= 1000; i++) {
		if (Max < who[i]) {
			Max = who[i];
			real = i;
		}
	}
	printf("%d\n%d\n", expect, real);
	return 0;
}