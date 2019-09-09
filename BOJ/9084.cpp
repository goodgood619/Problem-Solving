#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int coin[25];
int main()
{
	int T,n,money;
	scanf("%d",&T);
	while(T--){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&coin[i]);
	scanf("%d",&money);
    int dp[10010]={0,};
      dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=coin[i];j<=money;j++){
		dp[j]+=dp[j-coin[i]];
		}
	}
	printf("%d\n",dp[money]);
	}
	return 0;
}