#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<int, int>> a;
int n, x, y;
int cnt = 1;
int start, en;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		a.push_back(make_pair(y,x));
	}

	sort(a.begin(), a.end());
	en = a[0].first;
	for (int i = 1; i <n; i++) {
		if (a[i].second >=en)
		{
			cnt++;
			en = a[i].first;
		}
	}
	printf("%d\n", cnt);
	return 0;
}