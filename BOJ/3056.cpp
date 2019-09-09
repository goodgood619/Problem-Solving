#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;
double board[20][20];
int n;
double dp[1 << 20];
double go(int index,int ok){
	if (index == n) return 1;
	double &ret = dp[ok];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if ((ok&(1 << i)) == 0) {
			ret = max(ret, go(index + 1, ok | (1 << i))*board[index][i]);
		}
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %lf", &board[i][j]);
			board[i][j] /= 100;
		}
	}

	for (int i = 0; i < (1 << n); i++) { dp[i] = -1;}
	double ans=go(0,0);
	printf("%.12lf\n", ans*100);
	return 0;
}