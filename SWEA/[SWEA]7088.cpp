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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int t,n,q;
int Case = 1;
int sum1[100005];
int sum2[100005];
int sum3[100005];
int main() {
	scanf(" %d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		memset(sum3, 0, sizeof(sum3));
		int arr[100005] = { 0, };
		for (int i = 1; i <= n; i++) {
			scanf(" %d", &arr[i]);
		}
		for (int j = 1; j <= 3; j++) {
			for (int i = 1; i <= n; i++) {
				if (j == 1) {
					sum1[i] += sum1[i - 1];
					if (arr[i] == 1) sum1[i]++;
				}
				else if (j == 2) {
					sum2[i] += sum2[i - 1];
					if (arr[i] == 2) sum2[i]++;
				}
				else {
					sum3[i] += sum3[i - 1];
					if (arr[i] == 3) sum3[i] ++;
				}
			}
		}
		printf("#%d\n", Case++);
		for (int i = 1; i <= q; i++) {
			int left, right;
			scanf("%d%d", &left, &right);
			printf("%d %d %d\n", sum1[right] - sum1[left - 1], sum2[right] - sum2[left - 1], sum3[right] - sum3[left - 1]);
		}
	}
	return 0;
}