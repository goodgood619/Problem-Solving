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
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int rx[8] = { 0,0,1,-1,1,1,-1,-1 };
int ry[8] = { 1,-1,0,0,1,-1,1,-1 };
int n;
int isprime[1005];
int main() {
	for (int i = 2; i <= 1000; i++)isprime[i] = i;
	for (int i = 2; i <= sqrt(1000); i++) {
		if (isprime[i] == 0) continue;
		for (int j = i * i; j <= 1000; j += i) {
				isprime[j] = 0;
		}
	}
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (isprime[num] != 0) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}