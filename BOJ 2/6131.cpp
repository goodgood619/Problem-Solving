#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <cmath>
using namespace std;
typedef int64_t ll;
typedef int32_t ii;
int main() {
	ii n;
	scanf("%d", &n);
	vector<ii> v;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i) v.push_back(i);
			else {
				v.push_back(n / i);
				v.push_back(i);
			}
		}
	}
	sort(v.begin(), v.end());
	ii cnt = 0;
	for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
		ii x = v[i], y = v[j];
		double a = (x + y) / 2.0, b = (x-y)/2.0;
		if (a >= b && a == (ii)a && b == (ii)b) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}