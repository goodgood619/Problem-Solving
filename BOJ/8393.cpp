#include <stdio.h>
long long sum=0;

int main()
{
    int n;
     scanf("%d",&n);
      for(int i=1;i<=n;i++)
              sum+=i;
    printf("%lld\n",sum);
    return 0;
}