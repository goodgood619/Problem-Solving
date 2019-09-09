#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char num1[5];
char num2[5];
char ans[5];
int k = 4;
int main(){
	scanf("%s%s", num1, num2);

	for (int i = 0, j = strlen(num1) - 1; i <= j; i++, j--) {
		char c = num1[i];
		num1[i] = num1[j];
		num1[j] = c;
	}
	int sum1 = 0;
	int sum2 = 0;
	int length1 = strlen(num1);
	int length2 = strlen(num2);
	for (int i = length1-1; i>=0; i--) {
		int c = num1[i]-'0';
		sum1 += c*pow(10, length1-i-1);
	}
	for (int i = 0,j = strlen(num2) - 1; i <= j; i++, j--) {
		char c = num2[i];
		num2[i] = num2[j];
		num2[j] = c;
	}
	for (int i = length2-1; i>=0; i--) {
		int c = num2[i] - '0';
		sum2 += c*pow(10, length2-i-1);
	}
	int ne = sum1 + sum2;
	while (ne >0) {
		int a = ne % 10;
		ans[k--] = a + '0';
		ne /= 10;
	}

	for (int i = 0,j=4; i <=j; i++,j--) {
		if (ans[i] == '\0'){
			j++;
			continue;
		}
		else {
			char c = ans[i];
			ans[i] = ans[j];
			ans[j] = c;
		}
	}
	bool check = false;
	for (int i = 0; i < 5; i++) {
		if (ans[i] == '\0') continue;
		else if (ans[i] == '0' && !check){
			continue;
		}
		else{
			check = true;
			printf("%c", ans[i]);
		}
	}
	return 0;
}