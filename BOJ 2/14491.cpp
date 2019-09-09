#include <stdio.h>
#include <algorithm>
using namespace std;
int t;
void go(int t) {
	if (t < 9){
		printf("%d", t);
	}
	else {
		go(t / 9);
		printf("%d", t % 9);
	}
}
int main() {
	scanf("%d", &t);
	go(t);
	return 0;
}