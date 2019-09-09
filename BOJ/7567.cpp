#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char c[53];
char temp;
int cnt;
int main(){
	scanf("%s",c);
	int length = strlen(c);
	for (int i = 0; i < length; i++) {
		if (i == 0) {
			temp = c[i];
			cnt += 10;
		}
		else {
			if (temp == c[i]) {
				temp = c[i];
				cnt += 5;
			}
			else {
				temp = c[i];
				cnt += 10;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}