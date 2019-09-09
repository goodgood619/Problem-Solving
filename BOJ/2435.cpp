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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
int n, k;
int arr[105];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int left = 1,right=1;
	int sum = 0;
	int Max = -1e9;
	if (n == k) {
		for (int i = 1; i <= n; i++) {
			sum += arr[i];
		}
		printf("%d\n", sum);
		return 0;
	}
	while (left <= right) {
		if (right > n) {
			Max = max(sum, Max);
			break;
		}
		if (right - left < k) {
			sum += arr[right];
			right++;
		}
		else {
			Max = max(sum,Max);
			sum -= arr[left];
			left++;
		}
	}
	printf("%d\n", Max);
	return 0;
}