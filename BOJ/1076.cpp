#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int k = 0;
string s[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
string c;
int arr[3];
char ans[16];
int main() {
	for (int i = 0; i < 3; i++){
		cin >> c;
		for (int j= 0; j< 10; j++) {
			if (c == s[j]){
				arr[i] = j;
				break;
			}
		}
	}
	int cnt = 0;
	if (arr[0] == 0 && arr[1] == 0){
		printf("0\n");
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (i == 2 ) {
				for (int j = 0; j < arr[i]; j++) {
					ans[k++] = '0';
				}
			}
			else if (i == 0 && arr[i] + '0' == '0') {
				cnt++;
			}
			else {
				char c = arr[i] + '0';
				ans[k++] = c;
			}
		}

		for(int i=0;ans[i]!='\0';i++)
		printf("%c", ans[i]);
		printf("\n");
	}
	return 0;
}
