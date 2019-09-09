#include <stdio.h>
#include <algorithm>
using namespace std;
int a, b, c, d;
int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int sum = a + b + c + d;
	int minute = sum / 60;
	int second = sum % 60;
	printf("%d\n",minute);
	printf("%d\n",second);
	return 0;
}