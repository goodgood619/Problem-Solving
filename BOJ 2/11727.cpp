#include <stdio.h>
int main()
{
	int dp[1001]={};
	int n;
	dp[0]=1;
	dp[1]=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		dp[i]=(dp[i-1]+(2*dp[i-2]))%10007;
	printf("%d\n",(dp[n]%10007));
	return 0;
}