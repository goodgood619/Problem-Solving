#include <cstdio>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char s[9];
int sum,num;
int main(){
	scanf("%s", s);
	int length = strlen(s);
	for (int i = 0; i < length; i++){
		if (s[i] >= 'A' && s[i] <= 'F') {
			num = s[i] - 55;
		}
		else {
			num = s[i] - '0';
		}
		sum += num*pow(16, length - 1 - i);
	}
	printf("%d\n", sum);
	return 0;
}