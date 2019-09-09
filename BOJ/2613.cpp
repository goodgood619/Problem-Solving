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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int n, m;
int arr[305];
int main() {
	scanf("%d%d", &n, &m);
	int left = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		left = max(left, arr[i]);
	}
	vector<int> v,temp;
	int right = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		int sum = 0;
		int cur = 0;
		v.clear();
		for (int i = 1; i <= n; i++) {
			if (sum + arr[i] > mid) {
				v.push_back(cur);
				cnt++;
				sum = 0;
				cur = 0;
			}
			sum += arr[i];
			cur++;
		}
		if (sum > 0) {
			cnt++;
			v.push_back(cur);
		}
		if (cnt <= m) {
			temp = v;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", left);
	if (temp.size() == m) {
		for (int i = 0; i < temp.size(); i++) {
			printf("%d ", temp[i]);
		}
	}
	else {
		// left랑 값이 동일한 애들을 몇개를 더 추가시킬것인가
		int rest = m - temp.size();
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 1) printf("%d ", v[i]);
			else {
				while (rest > 0 && temp[i] >= 2) {
					printf("1 ");
					temp[i]--;
					rest--;
				}
				printf("%d ", temp[i]);
			}
		}
	}
	return 0;
}