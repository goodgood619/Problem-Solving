#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1010];
int arr[1010];
int ans=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)		
		scanf("%d",&arr[i]);
	for(int i=1;i<=n;i++)
		dp[i]=1;

	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
		if(arr[i]<arr[j])
		{
			dp[i]=max(dp[i],dp[j]+1);
		}
		}
	}

	for(int i=1;i<=n;i++)
	ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}