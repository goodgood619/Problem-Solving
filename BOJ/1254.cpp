#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char tempalin[2004];
bool check2;
bool check3;
int main(){
	scanf("%s", tempalin);
	int length = strlen(tempalin);
	bool check = false;
	for (int i = 0, j = length - 1; i <= j; i++, j--) {
		if (tempalin[i] ==tempalin[j]) continue;
		else check = true;
	}
	if (check) {
		for (int i = 0; i < length-1;) {
			check2 = false;
			for (int k = i, j = length - 1; k <= j; k++, j--) {
				if (tempalin[k] == tempalin[j]) continue;
				else {
					check2 = true; break;
				}
			}
			if (check2) i++;
			else {
				length += (i);
				check3 = true;
				break;
			}
		}
		if (check3) printf("%d\n", length);
		else printf("%d\n", 2 * length - 1);
	}
	else printf("%d\n", length);
	return 0;
}