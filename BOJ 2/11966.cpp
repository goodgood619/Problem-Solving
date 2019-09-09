#include <stdio.h>
#include <algorithm>
using namespace std;
long long n;
bool check;
int main() {
	scanf("%d", &n);
	for (long long i = 1;i<=n;i *= 2) {
		if (i == n){
			check = true;
			printf("1\n");
			break;
		}
	}
	if (!check) printf("0\n");
	return 0;
}