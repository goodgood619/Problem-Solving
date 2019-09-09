#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char pattern[102];
char front[102];
char back[102];
char test[102];
int n;
int Cnt;
bool visited[101];
int main(){
	scanf("%d", &n);
	scanf("%s", pattern);
	int cnt = strlen(pattern);
	for (int i = 0; pattern[i] != '*'; i++) {
		front[i] = pattern[i];
	}
	for (int i = cnt - 1; pattern[i] != '*'; i--) {
		back[i] = pattern[i];
	}
	for (int i = 0; i < n; i++){
		scanf("%s", test);
		memset(visited, false, sizeof(visited));
		int testlength = strlen(test)-1;
		int frontlength = strlen(front);
		int backlength = strlen(back);
		bool check = false;
		bool check2 = false;
		int k = 0;
		for(int i=0;i<frontlength;i++){
			if (front[i] != test[i]) {
				check = true; break;
			}
			else { visited[i] = true; continue; }
		}
		if (!check) {
			for (int i =cnt-1,j=testlength;pattern[i]!='*';i--,j--){
				if (back[i] != test[j] || visited[j]){
					check2 = true; break;
				}
				else continue;
			}
			if (!check2) printf("DA\n");
			else printf("NE\n");
		}
		else printf("NE\n");
	}
	return 0;
}
