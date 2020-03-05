#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (i == n / i) v.push_back(i);
			else {
				v.push_back(i);
				v.push_back(n/i);
			}
		}
	}

	sort(v.begin(), v.end());
	vector<int> ans;
	for (int i = 0, j = v.size() - 1; i <= j; i++, j--) {
		int x = v[j], y = v[i];
		double a = (x + y) / 2.0;
		double b = (x - y) / 2.0;
		if (a != (int)a || b != (int)b || b <= 0) continue;
		ans.push_back((int)a);
	}
	if (ans.size() == 0) printf("-1");
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}