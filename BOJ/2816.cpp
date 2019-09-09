#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,idx,idx2,k;
char channel[101][30];
char ans[600];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &channel[i]);
		if (!strcmp(channel[i], "KBS1")) {
			idx = i;
		}
		else if (!strcmp(channel[i], "KBS2")) {
			idx2 = i;
		}
	}
	int pos = 0;
		while (1) {
			if (idx == 0 && pos == 0) break;
			for (int i = 0; i < idx; i++) {
				pos++;
				ans[k++] = '1';
			}
			for (int i = idx; i > 0; i--){
				if (idx2 == idx - 1) {
					int temp = idx;
					idx = idx2;
					idx2 = temp;
					pos--;
					ans[k++] = '4';
					continue;
				}
				pos--;
				idx--;
				ans[k++] = '4';
			}
		}
		while (1) {
			if (idx2 == 1 && pos == 1) break;
			for (int i = 0; i < idx2; i++) {
				pos++;
				ans[k++] = '1';
			}
			for (int i = idx2; i > 1; i--) {
				pos--;
				idx2--;
				ans[k++] = '4';
			}
		}
		printf("%s\n", ans);
	return 0;
}