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
typedef pair<int, pair<int,int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t=10;
int go(int n, int m) {
	if (m == 0) return 1;
	return n*go(n, m - 1);
}
int main(){
	while (t--) {
		int Case, n, m;
		scanf("%d%d%d", &Case, &n, &m);
		printf("#%d %d\n", Case, go(n, m));
	}
	return 0;
}