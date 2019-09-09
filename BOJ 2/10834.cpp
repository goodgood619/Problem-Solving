#include <stdio.h>
#include <algorithm>
using namespace std;
int t;
int k = 1;
long long sc=1;
int rota[1001];
int main() {
	scanf("%d", &t);
	while (t--){
		int a, b;
		scanf("%d%d%d", &a, &b, &rota[k++]);
			sc *= b;
			sc /= a;
	}
	int st=rota[1];
	for (int i = 2; i < k; i++) {
		if (rota[i]==0){
			continue;
		}
		else {
			if (st == 0) st = 1;
			else st = 0;
		}
	}
	printf("%d %d\n", st, sc);
	return 0;
}