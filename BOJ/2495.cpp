#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char c[10];
int dp[10];
int ans;
int real[3];
char a, b,d;
int p = 0;
int main() {
	int t = 3;
	while (t--) {
		dp[0] = 1;
		scanf("%s", c);
		d = c[0];
		for (int i = 0; i < strlen(c) - 1; i++) {
			a = c[i];
			b = c[i + 1];
			//if (d== '0') continue;
			//if(a=='0' && b=='0')
			if (a != b)
				dp[i + 1] = 1;
			else
				dp[i + 1]=dp[i]+1;
		}
		for (int i = 0; i < strlen(c); i++) {
			ans = max(dp[i], ans);
		}
		real[p] = ans;
		ans = 0;
		for (int i = 0; i < strlen(c); i++)
			dp[i] = 0;
		p++;
	}
	printf("%d\n", real[0]);
	printf("%d\n", real[1]);
	printf("%d\n", real[2]);
	return 0;
}