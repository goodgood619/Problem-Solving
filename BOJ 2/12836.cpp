#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, k, m;
vector <long long> se;
int h = 1;
void update(int index, int value) {
	index += h - 1;
	se[index]+= value;
	while (index > 1) {
		index /= 2;
		se[index] = se[2 * index] + se[2 * index + 1];
	}
}
long long query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return se[nodeNum];
	else if (L > nodeR || R < nodeL) return 0;
	int mid = (nodeL + nodeR) / 2;
	//왼쪽+오른쪽
	return query(L, R, nodeNum * 2, nodeL, mid) + query(L, R, nodeNum * 2 + 1, mid + 1, nodeR);
}
int main() {
	scanf("%d%d", &n, &m);
	while (h < n)h <<= 1;
	se.resize(h * 2);
	for (int j = 0; j < m; j++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 1)
			update(b, c);
		else if (a == 2) {
			long long hab = query(b, c, 1, 1, h);
			printf("%lld\n", hab);
		}
	}
	return 0;
}
