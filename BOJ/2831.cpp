#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt;
int men[100001];
int women[100001];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &men[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &women[i]);
	sort(men + 1, men + n + 1);
	sort(women + 1, women + n + 1);

	for (int i = 1,j=n; i <= n && j>=1;) {
		if (men[i] < 0){
			if (men[i] == -1500) {
				i++;
				continue;
			}
			if (men[i] + women[j] == 0) {
				j--; 
				continue;
			}
			else if(men[i]+women[j]<0 && men[i]<0 && women[j]>0){
				cnt++;
				i++;
				j--;
			}
			else if (men[i] + women[j] > 0) {
				j--;
				continue;
			}
			else if(men[i]+women[j]<0 && men[i]<0 && women[j]<0){
				i++;
				continue;
			}
		}
		else{
			if (men[i] == 2500) {
				i++;
				continue;
			}
			if (men[i] + women[j] == 0) {
				j--;
				continue;
			}
			else if(men[i]+women[j]<0 && men[i]>0 && women[j]<0){
				cnt++;
				i++;
				j--;
			}
			else if (men[i] + women[j] > 0) {
				j--;
				continue;
			}
			else if(men[i]+women[j]>0 && men[i]>0 && women[j]>0){
				j--;
				continue;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}