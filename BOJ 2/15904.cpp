#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
char s[1005];
int main(){
	scanf("%[^\n]s", s);
	int length = strlen(s);
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		if (cnt == 0 && s[i] == 'U') {
			cnt++;
		}
		else if (cnt == 1 && s[i] == 'C') {
			cnt++;
		}
		else if (cnt == 2 && s[i] == 'P') {
			cnt++;
		}
		else if (cnt == 3 && s[i] == 'C') {
			cnt++;
		}
	}
	if (cnt == 4) printf("I love UCPC\n");
	else printf("I hate UCPC\n");
	return 0;
}