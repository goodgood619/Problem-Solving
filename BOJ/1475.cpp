#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char s[9];
int cnt,zerocnt;
int arr[10];
int main(){
	scanf("%s", s);
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		int num = s[i] - '0';
		arr[num]++;
	}

	for (int i = 0; zerocnt != 10; i++) {
		zerocnt = 0;
		for (int j= 0; j < 10; j++) {
			if (arr[j] > 0) arr[j]--;
			else if (arr[j] == 0 && j == 6){
				if(arr[9]>0) arr[9]--;
			}
			else if (arr[j] == 0 && j == 9) {
				if(arr[6]>0) arr[6]--;
			}
		}
		cnt++;
		for (int k= 0; k < 10; k++) {
			if (arr[k] == 0) zerocnt++;
			else continue;
		}
	}
	printf("%d\n", cnt);
	return 0;
}