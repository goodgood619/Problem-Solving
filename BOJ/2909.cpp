#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int k;
char c[15];
int main(){
	scanf("%s%d", c, &k);
	int length = strlen(c);
	//액면가가 더 큰 경우
	if(k >= length){
		int total = pow(10, k);
		total /= 2;
		int sum = 0;
		for (int i = 0; i < length; i++){
			int a = c[i] - '0';
			sum += (pow(10, length-1-i)*a);
		}
		if (sum >= total) printf("%d\n", total*2);
		else printf("0\n");
	}
	else{
		int total = pow(10, k);
		int q = total;
		total /= 2;
		int p = 0;
		int sum = 0;
		int real = 0;
		for (int i = length - 1; i >= 0; i--) {
			int x = c[i] - '0';
			real +=(pow(10, length-1-i)*x);
		}
		for (int i = length - 1; p < k; i--){
			int s = c[i] - '0';
			sum += pow(10,p)*s;
			p++;
		}
		if (q > total + sum){
			real -= sum;
			printf("%d\n", real);
		}
		else {
			real += (q - sum);
			printf("%d\n", real);
		}
	}
	return 0;
}