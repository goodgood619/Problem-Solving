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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
bool check[1000005];
int cnt[105];
int n;
int main() {
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			check[j] = true;
		}
	}
	vector<int> v;
	for (int i = 2; i <= 1000000; i++) {
		if (!check[i]) v.push_back(i);
	}
	scanf("%d", &n);
	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf(" %d", &num);
		arr.push_back(num);
	}
	int Max = 1, Min = 0;
	for (int i = 0; i <v.size(); i++) {
		int mod=v[i];
		int sum = 0;
		for (int j = 0; j < arr.size(); j++) {
			int here = arr[j];
			cnt[j] = 0;
			while (here%mod== 0) here /= mod, cnt[j]++;
			sum += cnt[j];
		}
		for (int i = 0; i < sum / n; i++) Max *= mod;
		for (int i = 0; i < n; i++) Min += max(sum / n - cnt[i], 0);
	}
	printf("%d %d\n", Max, Min);
	return 0;
}