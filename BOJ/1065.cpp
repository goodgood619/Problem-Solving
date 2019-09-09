#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt;
int go(int num){
	if (num <= 999) {
		int first = (num / 100)-((num / 10)%10);
		int second = ((num / 10) % 10) - (num % 10);
		if (first == second) return 1;
		else return 0;
	}
	else if (num == 1000) {
		return 0;
	}
}
int main() {
	scanf("%d", &n);
	if (n < 100)
		cnt += n;
	else {
		cnt += 99;
		for (int i = 100; i <= n; i++) {
			cnt+=go(i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}