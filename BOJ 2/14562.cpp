#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int ans = 999999999;
void go(int first, int second,int cnt) {
	if (first > second) return;
	if (first == second){
		ans = min(ans, cnt);
		return;
	}
	go(first + 1, second, cnt+1);
	go(first + first, second + 3, cnt+1);
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		ans = 99999999;
		go(first, second,0);
		printf("%d\n", ans);
	}
	return 0;
}