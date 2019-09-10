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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
typedef unsigned long long lll;
int arr[10000001];
int main() {
	setbuf(stdout, NULL);
	int n;
	ll total = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			scanf("%d", &num);
			arr[num]++;
			total += num;
		}
	}

	if (n*n == arr[0]) {
		printf("0\n");
		return 0;
	}
	ll downcnt = n * n - arr[0];
	ll sum = 0;
	for (int i = 1; i <= 10000000; i++) {
		sum += downcnt; //맨아래층
		downcnt -= arr[i]; //1층부터, n층까지의 계단 제거
		if (sum * 2 >= total) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}