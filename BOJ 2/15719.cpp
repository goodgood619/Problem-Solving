#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <bitset>
using namespace std;
bool visited[10000005];
bitset <10000005> c;
int n,ans;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int num;
		scanf("%d", &num);
		if (c[num] == false) {
			c.set(num, true);
			continue;
		}
		else {
			ans = num;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}