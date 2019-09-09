#include <cstdio>
#include <algorithm>
using namespace std;
int n;
long long cnt;
void hanoi(int n, int st, int by, int to) {
	if (n == 1){
		cnt++;
		return;
	}
	else{
		hanoi(n - 1, st, to, by);
		cnt++;
		hanoi(n - 1, by, st, to);
	}
}
void hanoi2(int n, int st, int by, int to) {
	if (n == 1) {
		printf("%d %d\n", st, to);
		return;
	}
	else {
		hanoi2(n - 1, st, to, by);
		printf("%d %d\n", st, to);
		hanoi2(n - 1, by, st, to);
	}
}
int main(){
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("%lld\n", cnt);
	hanoi2(n, 1, 2, 3);
	return 0;
}