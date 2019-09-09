#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int t,p;
void go(int n);
int ans[10000];
int main(){
	scanf("%d", &t);
	while (t--) {
		memset(ans, 0, sizeof(ans));
		p = 0;
		int n;
		scanf("%d", &n);
		go(n);
		for (int i = 0; i < p / 2; i++){
			int temp = ans[i];
			ans[i] = ans[p-1- i];
			ans[p -1- i] = temp;
		}
		for (int i = 0; i < p; i++) {
			if (ans[i] == 1)printf("%d ", i);
			else continue;
		}
		printf("\n");
	}
	return 0;
}
void go(int n){
	if (n < 2){
		ans[p++] = n;
		return;
	}
	else {
		go(n / 2);
		go(n % 2);
	}
}