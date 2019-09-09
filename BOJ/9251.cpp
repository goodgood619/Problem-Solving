#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
char a[1005];
char b[1005];
int dp[1005][1005];
int go(int aidx,int bidx){
	int &ret = dp[aidx][bidx];
	if (aidx < 0 || bidx < 0) return 0;
	if (ret != -1) return ret;
	if (a[aidx] == b[bidx]) {
		ret = max(ret, go(aidx - 1, bidx - 1) + 1);
	}
	else {
		ret = max(go(aidx - 1, bidx), ret);
		ret = max(go(aidx, bidx - 1), ret);
	}
	return ret;
}
int main(){
	scanf("%s", a);
	scanf("%s", b);
	int length1 = strlen(a) - 1;
	int length2 = strlen(b) - 1;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(length1, length2));
	return 0;
}