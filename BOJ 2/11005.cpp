#include <cstdio>
#include <algorithm>
using namespace std;
char ans[1000];
int num,n,k;
void go(int num){
	if (num < n){
		if (num >= 10 && num <= n && n>10){
			ans[k++] = num + 55;
			return;
		}
		else{
			ans[k++] = num + '0';
			return;
		}
	}
	else {
		go(num / n);
		go(num%n);
	}
}
int main(){
	scanf("%d%d", &num, &n);
	go(num);
	printf("%s\n", ans);
	return 0;
}