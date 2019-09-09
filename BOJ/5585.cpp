#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt;
int main(){
	scanf("%d", &n);
	int rest = 1000 - n;
	while (rest > 0) {
		if (rest == 0) break;
		if (rest >= 500){
			cnt++;
			rest -= 500;
		}
		else if (rest >= 100 && rest < 500){
			cnt++;
			rest -= 100;
		}
		else if (rest >= 50 && rest < 100) {
			cnt++;
			rest -= 50;
		}
		else if (rest >= 10 && rest < 50)
		{
			cnt++;
			rest -= 10;
		}
		else if(rest>=5 && rest<10){
			cnt++;
			rest -= 5;
		}
		else {
			cnt++;
			rest -= 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}