#include<stdio.h>
int main()
{
	int numb;
	double A, B, C, num;
	scanf("%lf %lf %lf", &A, &B, &C);
	if (C <= B) printf("-1");
	else
	{
		num = A / (C - B);
		numb = (int)num;
		printf("%d\n", numb + 1);
	}
}