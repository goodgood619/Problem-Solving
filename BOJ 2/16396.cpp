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
int n, k;
int arr[15];
int Max = -2000000000;
int Min = INT_MAX;
vector<P> v;
int check[10005];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		for (int j = first; j < second; j++) {
			check[j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 10000; i++) {
		if (check[i]) cnt++;

	}
	printf("%d\n", cnt);
	return 0;
}