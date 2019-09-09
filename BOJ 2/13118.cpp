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
typedef pair<ll, int> P;
typedef pair<int, pair<int, ll>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int p1, p2, p3, p4,x,y,r;
int arr[4];
int main() {
	scanf("%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3]);
	scanf("%d%d%d", &x, &y, &r);
	if (y != 0)y = 0;
	int num = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i] == x){
			num = i + 1;
			break;
		}
	}
	printf("%d\n", num);
	return 0;
}