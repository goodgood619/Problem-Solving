#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cstring>
using namespace std;
char s[350000];
int ans[3];
int k=2;
bool flag;
void go(int num,int p) {
	if (num<2) {
		ans[p--] = num;
		return;
	}
	else {
		go(num / 2,p-1);
		go(num % 2,p);
	}
}
int main(){
	scanf("%s",s);
	int length = strlen(s);
	if (s[0] - '0' == 0) printf("0\n");
	else {
		for (int i = 0; i < length; i++){
			k = 2;
			memset(ans, 0, sizeof(ans));
			int num = s[i] - '0';
			go(num,k);
			if (!flag) {
				for (int j = 0; j < 3; j++){
					if (num >= 4) {
						printf("%d", ans[j]);
					}
					else if(num>=2 && num<4){
						if (ans[0] == 0 && j == 0) continue;
						else printf("%d", ans[j]);
					}
					else if (num == 1) {
						if (ans[0] == 0 && j == 0) continue;
						else if (ans[1] == 0 && j == 1) continue;
						else printf("%d", ans[j]);
					}
				}
				flag = true;
			}
			else {
				for (int j = 0; j < 3; j++) {
					printf("%d", ans[j]);
				}
			}
		}
	}
	return 0;
}