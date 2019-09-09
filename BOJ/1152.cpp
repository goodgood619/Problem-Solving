#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char c[1000001];
int cnt;
bool check;
int main() {
	scanf("%[^\n]s", c);
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] != ' ' &&!check){
			check = true;
			cnt++;
		}
		else if (c[i] != ' '&& check) continue;
		else if(c[i]==' '){
			check = false;
			continue;
		}
	}
	printf("%d\n", cnt);
	return 0;
}