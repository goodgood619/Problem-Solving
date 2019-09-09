#include <cstdio>
#include <algorithm>
using namespace std;
int N, m, M, T, R;
int main() {
	scanf("%d%d%d%d%d", &N, &m, &M, &T, &R);
	int exercnt = 0;
	int current = m;
	int cnt = 0;
	if (current + T > M) printf("-1\n");
	else {
		while (1) {
			if (exercnt == N) break;
			if (current + T <= M) {
				current += T;
				exercnt++;
				cnt++;
			}
			else {
				current -= R;
				if (current < m) current = m;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}