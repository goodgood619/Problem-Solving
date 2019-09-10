#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;
vector<ll> p;
vector<ll> q;
int n, m;
ll arr[10005];
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%lld", &arr[i]);}
	sort(arr + 1, arr + n + 1);
	int left1 = 1;
	int left2 = 2;
	int right1 = n;
	int right2 = n - 1;
	int right3 = n - 2;
	ll Max = 0;
	Max = max(Max, arr[left1] * arr[left2]);
	Max = max(Max, arr[left1] * arr[right1]);
	Max = max(Max, arr[right1] * arr[right2]);
	Max = max(Max, arr[right3] * arr[right2]*arr[right1]);
	Max = max(Max, arr[left1] * arr[left2]*arr[right1]);
	printf("%lld\n", Max);
	return 0;
}