#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int isprime[1501];
char c[21];
int cnt;
void go() {
	for (int i = 2; i <= sqrt(1500); i++){
		if (isprime[i] == 0) continue;
		for (int j = i*i;j<=1500;j += i) {
			isprime[j] = 0;
		}
	}
}
int main(){
	for (int i = 1; i <=1500; i++) {
		isprime[i] = i;
	}
	go();
	scanf("%s", c);

	for (int i = 0; i < strlen(c); i++) {
		if (c[i] >= 'a' && c[i] <= 'z') {
			int aa = c[i] - 96;
			cnt += aa;
		}
		else if (c[i] >= 'A'&& c[i] <= 'Z') {
			int bb = c[i] - 38;
			cnt += bb;
		}
	}

	if (isprime[cnt]) printf("It is a prime word.\n");
	else printf("It is not a prime word.\n");
	return 0;
}