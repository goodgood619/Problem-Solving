#include <cstdio>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
char c[100];
int f,idx;
int main(){
	scanf("%s", c);
	scanf("%d", &f);
	int length = strlen(c);
	int sum = 0;
	for (int i = 0; i < length; i++){
		int num = c[i] - '0';
		if (i == length - 2 || i == length - 1) continue;
		else {
			sum += num*(pow(10, length - 1 - i));
		}
	}

	for (int i = sum; i <= sum + 99; i++) {
		if (i%f == 0){
			idx = i;
			idx -= sum;
			break;
		}
		else continue;
	}
	if (idx < 10) printf("0%d\n", idx);
	else printf("%d\n", idx);
	return 0;
}