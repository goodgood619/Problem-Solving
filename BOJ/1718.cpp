#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char plain[30010];
char password[30010];
char temp[30010];
int main(){
	scanf("%[^\n]s", plain);
	scanf("%s", password);
	int length = strlen(plain);
	int length2 = strlen(password);
	for (int i = 0,j=0; i < length; i++,j++){
		if (j >= length2) j = 0;
		if (plain[i] == ' ') {
			temp[i] = ' ';
			continue;
		}
		else {
			int num = (plain[i] -96) - (password[j] -96);
				if (num < 0) {
					temp[i] = (26 - abs(num)) + 96;
				}
				else if(num>0){
					temp[i] = num +96;
				}
				else if(num==0){
					temp[i] = 'z';
				}
		}
	}
	printf("%s\n", temp);
	return 0;
}