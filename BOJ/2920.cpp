#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[8];
int ascend,descend;
int main(){
	for(int i=0;i<8;i++) scanf("%d", &arr[i]);
	for (int i = 0; i < 7; i++) {
		if (arr[i + 1] - arr[i] == 1) {
			ascend++;
		}
		else if (arr[i + 1] - arr[i] == -1) {
			descend++;
		}
	}
	if (ascend == 7) printf("ascending\n");
	else if (descend == 7) printf("descending\n");
	else printf("mixed\n");
 	return 0;
}