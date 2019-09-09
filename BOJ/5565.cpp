#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int book[10];
int main() {
	scanf("%d", &n);
	for (int i = 0; i <9; i++) {
		scanf("%d", &book[i]);
		n -= book[i];
	}
	printf("%d\n", n);
	return 0;
}