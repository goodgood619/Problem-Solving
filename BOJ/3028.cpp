#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
char s[55];
int main(){
	scanf("%s", s);
	int length = strlen(s);
	// A: 1,2 or 2,1
	// B: 2,3 or 3,2
	// C: 1,3 or 3,1
	int start=1;
	for (int i = 0; i < length; i++) {
		char c = s[i];
		if (c == 'A'){
			if (start == 1) {
				int en = 2;
				int temp = start;
				start = en;
				en = temp;
				continue;
			}
			if (start == 2) {
				int en = 1;
				int temp = start;
				start = en;
				en = temp;
				continue;
			}
		}
		else if (c == 'B'){
			if (start == 2) {
				int en = 3;
				int temp = start;
				start = en;
				en = temp;
				continue;
			}
			if (start == 3) {
				int en = 2;
				int temp = start;
				start = en;
				en = temp;
				continue;
			}
		}
		else if (c == 'C') {
			if (start == 1) {
				int en = 3;
				int temp = start;
				start = en;
				en = temp;
				continue;
			}
			if (start == 3) {
				int en = 1;
				int temp = start;
				start = en;
				en = temp;
				continue;
			}
		}
	}
	printf("%d\n", start);
	return 0;
}