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
using namespace std;
typedef long long ll;
int arr[1005];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);
	sort(arr + 1, arr + n + 1);
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] < n + 1 - i) continue; // 답이긴 한데 최대값이 아니니까 넘기자
		else {
			printf("%d\n", n + 1 - i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}