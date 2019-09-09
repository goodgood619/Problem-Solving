#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;
char s[1004];
int n;
int main(){
	scanf("%d", &n);
	while (n--){
		scanf("%s", s);
		int length = strlen(s);
		bool check = false;
		for (int i = 0, j = length - 1; i < j; i++, j--) {
			if (s[i] == s[j]) check = true;
			else check = false;
		}
		if (check) printf("Do-it\n");
		else printf("Do-it-Not\n");
	}
	return 0;
}