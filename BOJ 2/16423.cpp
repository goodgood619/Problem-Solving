#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
pair<int, int> arr[1001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	int ok = 0,Max=0;
	for (int i = n; i >= 1; i--) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[j].first <= i && i <= arr[j].second) temp++;
		}
		if (temp == i) {
			Max = max(Max, i);
			ok = 1;
		}
	}
	ok ? printf("%d\n", Max) : printf("-1\n");
	return 0;
}