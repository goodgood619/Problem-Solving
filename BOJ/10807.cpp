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
	int n;
	scanf("%d", &n);
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		m[num]++;
	}
	int p;
	scanf("%d", &p);
	printf("%d\n", m[p]);
	return 0;
}