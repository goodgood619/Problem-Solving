#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[5][3];
int dp[5];
int sum=0;
int ans=0;
int main(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=2;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	dp[1]=arr[1][2];
	for(int i=2;i<=4;i++)
	{
		sum=dp[i-1];
		dp[i]=max(dp[i],sum+dp[i]+arr[i][2]-arr[i][1]);
	}
	for(int i=1;i<=4;i++)
	ans=max(ans,dp[i]);
	printf("%d\n",ans);	
	return 0;
}