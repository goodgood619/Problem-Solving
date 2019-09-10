#include <cstdio>
#include <algorithm>
using namespace std;
int hwal[30001];
int n,Max;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &hwal[i]);}

	for (int i = 1; i <= n; i++){
		int cnt = 0;
		for (int j = i+1; j <= n; j++) {
			if (hwal[i] > hwal[j]){
				cnt++;
			}
			else break;
		}
		Max=max(cnt, Max);
	}
	printf("%d\n", Max);
	return 0;
}