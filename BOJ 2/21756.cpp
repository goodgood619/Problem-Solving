#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);

	vector<int> v;
	v.assign(n + 1, 0);
	for (int i = 0; i <= n; i++) {
		v[i] = i;
	}
	int ans = 0;
	if (n == 1) {
		printf("%d\n", 1);
		return 0;
	}
	while (true) {
		vector<int> temp;
		temp.assign(n + 1, 0);
		for (int i = 1; i <= n; i += 2) {
			v[i] = 0;
		}

		int idx = 1;
		for (int i = 1; i <= n; i++) {
			if (v[i] != 0) {
				temp[idx++] = v[i];
			}
		}
		v = temp;
		if (idx == 2) {
			ans = temp[idx - 1];
			break;
		}		
	}
	printf("%d\n", ans);
	return 0;
}