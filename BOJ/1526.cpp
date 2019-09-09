#include <cstdio>
#include <algorithm>
using namespace std;
int n,Max;
void go(int depth, int num) {
	if (depth >= 7) return;
	if (num <= n) {
		Max=max(num,Max);
	}
	go(depth + 1, num * 10 + 4);
	go(depth + 1, num * 10 + 7);
}
int main(){
	scanf("%d", &n);
	go(0, 0);
	printf("%d\n", Max);
	return 0;
}