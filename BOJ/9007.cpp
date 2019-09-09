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
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int t;
int arr[5][1005];
int main(){
	scanf("%d",&t);
	while (t--){
		int n, k;
		vector<int> up;
		vector<int> down;
		scanf("%d%d", &n, &k);
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= k; j++) {
				scanf(" %d", &arr[i][j]);
			}
		}
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= k; j++) {
				up.push_back(arr[1][i] + arr[2][j]);
				down.push_back(arr[3][i] + arr[4][j]);
			}
		}
		int Max = 0;
		int diff = 2100000000;
		sort(up.begin(), up.end());
		sort(down.begin(), down.end());
		for (int i = 0; i < up.size(); i++) {
			int upsum = up[i];
			int left, right;
			vector<int>::iterator it = lower_bound(down.begin(), down.end(), n - upsum);
			vector<int>::iterator it2;
			if (it == down.end()) {
				right = 1e8;
				it--;
				right = *it;
				left = *(--it);
			}
			else if (it == down.begin()) {
				left = 1e8;
				right = *it;
			}
			else {
				it2 = it;
				it2--;
				right = *it;
				left = *it2;
			}
			if (diff>abs(n - upsum -right)) {
				diff = abs(n - upsum -right);
				Max = upsum + right;
			}
			if (diff >= abs(n - upsum -left)) {
				diff = abs(n - upsum -left);
				Max = upsum +left;
			}
		}
		printf("%d\n", Max);
	}
	return 0;
}