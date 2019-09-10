#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
ll n, a, b;
string s;
#define mod 26
char alpha[100];
int dp[1000005];
int main() {
	int n;
	int Max = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		dp[num] = max(dp[num], dp[num - 1] + 1);
		Max = max(dp[num], Max);
	}
	printf("%d\n", Max);
	return 0;
}