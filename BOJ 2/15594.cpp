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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n;
int arr[105];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	int ok = 0;
	for (int k = 1; k < n; k++) {
		if (arr[k] > arr[k + 1]) {
			ok = 1;
			break;
		}
	}
	if (!ok) {
		printf("0\n");
		return 0;
	}
	for (int i = n;;) {
		int no = 0;
		int here = arr[i];
		for (int k = i-1; k >=1; k--) {
			if (here< arr[k]) {
				no = 1;
				break;
			}
		}
		if (!no) {
			i--;
			continue;
		}
		here = arr[i];
		int idx = i;
		for (int j = n; j >= 1; j--) {
			if (arr[j] > here) {
				if (idx > j) {
					idx = j;
				}
			}
		}
		swap(arr[i], arr[idx]);
		no = 0;
		for (int k = 1; k < n; k++) {
			if (arr[k] > arr[k + 1]) {
				no = 1;
				break;
			}
		}
		if (!no) break;
		cnt++;
	}
	printf("%d\n", cnt+1);
	return 0;
}