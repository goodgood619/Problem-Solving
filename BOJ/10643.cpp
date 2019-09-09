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
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int n, k;
int arr[20];
int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 8; i < 8 + 8; i++) {
		arr[i] = arr[i - 8];
	}
	int Max = 0;
	for (int i = 0; i < 8; i++) {
		Max = max(Max, arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3]);
	}
	printf("%d\n", Max);
	return 0;
}