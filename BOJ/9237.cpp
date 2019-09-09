#include <stdio.h>
#include <algorithm>
using namespace std;
int n,Max;
int mok[100001];
int realmok[100001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &mok[i]);
	}
	sort(mok + 1, mok + n + 1);
	for (int i = n,j=1; i >= 1; i--,j++) {
		realmok[i] = mok[j];
	}

	for (int i = 1; i <= n; i++) {
		Max = max(Max, realmok[i] + i);
	}
	printf("%d\n", Max + 1);
	return 0;
}