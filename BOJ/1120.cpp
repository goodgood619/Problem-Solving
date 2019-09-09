#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char a[55];
char b[55];
int Min = 99999999;
int main(){
	scanf("%s%s", a, b);
	int length1=strlen(a);
	int length2 = strlen(b);
	for (int i = 0; i <=length2 - length1; i++){
		int cnt = 0;
		for (int j = 0; j < length1; j++) {
			if (a[j] == b[i + j]) continue;
			else cnt++;
		}
		Min = min(Min, cnt);
	}
	printf("%d\n", Min);
	return 0;
}