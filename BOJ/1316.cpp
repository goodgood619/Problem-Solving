#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	int cnt = 0;
	while (t--) {
		char word[105] = { '\0', };
		char check[105] = { '\0', };
		scanf("%s", word);
		int length = strlen(word);
		int p = 0;
		char current = word[0];
		bool real = false;
		check[0] = current;
		p++;
		for (int i = 1; i < length; i++) {
			if (current == word[i]) continue;
			else{
				for (int k = 0; k < p; k++) {
					if (check[k] != word[i]) continue;
					else real = true;
				}
				check[p] = current;
				current = word[i];
				p++;
			}
			if (real) break;
		}
		if (!real) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}