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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n,h,s,g,d;
int arr[15];
int Max = -2000000000;
int Min = INT_MAX;
bool ok;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void go(int index, int cnt, int sum, int depth, int h, int s, int g, int d) {
	if (cnt == depth){
		Max = max(Max, sum);
		Min = min(Min, sum);
		return;
	}
	if (h > 0) go(index + 1, cnt + 1, sum + arr[index], depth, h - 1, s, g, d);
	if (s > 0) go(index + 1, cnt + 1, sum - arr[index], depth, h, s - 1, g, d);
	if (g > 0) go(index + 1, cnt + 1, sum*arr[index], depth, h, s, g - 1, d);
	if (d > 0) go(index + 1, cnt + 1, sum / arr[index], depth, h, s, g, d - 1);
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]);}
	scanf("%d%d%d%d", &h, &s, &g,&d);
	go(1, 1,arr[0], n, h, s, g, d);
	printf("%d\n%d\n", Max, Min);
	return 0;
}