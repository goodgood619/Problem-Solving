#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int t, s, n;
typedef pair<int, int> P;
P anspo[100005];
int main() {
	scanf("%d%d", &t, &s);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		anspo[i].first = i;
		anspo[i].second = num;
	}
	int p = t-s;
	int ans = n;
	for (int ti =0; ti <=100000; ti++){
		for (int j = 1; j <= n; j++){
			if (ti%anspo[j].second == 0) {
				p--;
				ans = j;
				if (p == 0) break;
			}
		}
		if (p == 0) break;
	}
	printf("%d\n", ans);
	return 0;
}

