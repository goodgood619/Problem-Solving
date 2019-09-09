#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int t,cnt,Cnt,q,idx;
int k = 1;
char s[25];
int n, m;
char poke[150][25];
int Max[150];
int main() {
	scanf("%d", &t);
	int p = t;
	while (t--){
		Cnt = 0;
		scanf("%s", s);
		scanf("%d%d", &n, &m);
		for (; m>=n;) {
			m -= n;
			m += 2;
			Cnt++;
		}
		Max[k] = Cnt;
		cnt += Cnt;
		strcpy(poke[k], s);
		k+=2;
	}
	for (int i = 1; i <= 2*p-1; i+=2){

		if (q >= Max[i])continue;
		else {
			q = Max[i];
			idx = i;
		}
	}
	printf("%d\n", cnt);
	printf("%s\n", poke[idx]);
	return 0;
}