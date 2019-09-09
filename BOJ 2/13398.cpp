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
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,temp;
int cur = -1e9;
int Max = -1e9;
priority_queue<P, vector<P>, greater<P>> pq;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		temp = max(cur, temp + num);
		cur = max(cur+num,num);
		Max = max(Max, max(cur, temp));
	}
	printf("%d\n", Max);
	return 0;
}