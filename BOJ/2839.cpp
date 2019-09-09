#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int ans = 99999999;
bool check;
int main() {
	int five = 0;
	int three = 0;
	scanf("%d", &n);
	five = n / 5;
	five += 1;
		for (int i = five; i >= 0; i--) {
			int p = n;
			p -= 5 * i;
			if (p < 0) continue;
			else if (p == 0) { ans = min(i, ans); continue;}
			for (int j = 1;; j++){
				int q = p;
				q-= 3 * j;
				if (q>0) continue;
				else if(q==0){
					ans = min(i + j, ans);
					break;
				}
			else if (q < 0) break;
			}
		}
		if (ans == 99999999) printf("-1\n");
		else printf("%d\n", ans);
	return 0;
}