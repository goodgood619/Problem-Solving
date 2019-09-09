#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char num1[100];
char num2[100];
char temp[100];
char what[2];
int main(){
	scanf("%s", num1);
	scanf("%s", what);
	scanf("%s", num2);

	int oneleng = strlen(num1);
	int twoleng = strlen(num2);
	if (what[0] == '+'){
		if (oneleng == twoleng){
			for (int i = 0; i < oneleng; i++) {
				if (num1[i] == '1') {
					temp[i] = '2';
					continue;
				}
				else temp[i] = '0';
			}
			printf("%s\n", temp);
		}
		else {
			int Max = max(oneleng, twoleng);
			if (oneleng < twoleng) {
				int dif = twoleng - oneleng;
				for (int i = oneleng-1; i>=0; i--) {
					num1[i + dif] = num1[i];
					num1[i] = ' ';
				}
			}
			else {
				int dif = oneleng - twoleng;
				for (int i =twoleng-1; i>=0; i--) {
					num2[i + dif] = num2[i];
					num2[i] = ' ';
				}
			}

			for (int i = 0; i < Max; i++) {
				if (num1[i] == '1') { temp[i] = '1';}
				else if (num2[i] == '1') { temp[i] = '1';}
				else temp[i] = '0';
			}
			printf("%s", temp);
		}
	}
	else if (what[0] == '*') {
		for (int i = 0; i < oneleng + twoleng - 1; i++) {
			if (num1[i] == '1') {
				temp[i] = '1'; continue;
			}
			temp[i] = '0';
		}
		printf("%s", temp);
	}
	return 0;
}