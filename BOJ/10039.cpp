#include <stdio.h>
int main()
{
	int arr[5];
	int sum=0;
	int avg;
	for(int i=0;i<5;i++)
	scanf("%d",&arr[i]);
	
	for(int i=0;i<5;i++)
	{
		if(arr[i]<40)
		{
			arr[i]=40;
		}
	sum+=arr[i];
	}
	avg=sum/5;
	printf("%d\n",avg);
	return 0;
}