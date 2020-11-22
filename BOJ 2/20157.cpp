#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	map<double, int> arrowCnt[4];
	for (int i = 0; i < n; i++) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		y /= x;
		//1사분면
		if (x > 0 && y > 0) {
			arrowCnt[0][y]++;
		}
		//2사분면
		else if (x > 0 && y<0) {
			arrowCnt[1][y]++;
		}
		//3사
		else if (x < 0 && y < 0) {
			arrowCnt[2][y]++;
		}
		//4사
		else {
			arrowCnt[3][y]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (auto it = arrowCnt[i].begin(); it != arrowCnt[i].end(); it++) {
			ans = max(ans, it->second);
		}
	}
	printf("%d\n", ans);
	return 0;
}