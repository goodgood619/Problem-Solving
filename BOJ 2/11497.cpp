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
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<int> v;
		int arr[10005] = { 0, };
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		int left = 1;
		int right = n;
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!flag) {
				arr[left++] = v[i];
				flag = true;
			}
			else {
				arr[right--] = v[i];
				flag = false;
			}
		}
		int Max = 0;
		for (int i = 1; i <n; i++) {
			Max = max(Max, abs(arr[i] - arr[i + 1]));
		}
		Max = max(Max, abs(arr[n] - arr[1]));
		printf("%d\n", Max);
	}
	return 0;
}