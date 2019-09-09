#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;
int t;
int alphacnt[28];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(alphacnt, 0, sizeof(alphacnt));
		char c[100005] = { '\0', };
		char temp[100005] = { '\0', };
		scanf("%s", c);
		int length = strlen(c);
		int p = 0;
		for (int i = 0; i < length; i++) {
			int num = c[i] - 'A';
			if (alphacnt[num] != 3) {
				alphacnt[num]++;
				if (alphacnt[num] == 3) {
					temp[p++] = c[i];
					temp[p++] = c[i];
					alphacnt[num] = 0;
					i++;
					continue;
				}
				temp[p++] = c[i];
			}
		}
		if (!strcmp(c, temp)) printf("OK\n");
		else printf("FAKE\n");
	}
	return 0;
}