#include <cstdio>
#include <algorithm>
#include <string.h>
#include <bitset>
#include <math.h>
using namespace std;
int ok;
int n;
char c[20];
bitset <33554432> bt;
int main(){
	while (scanf("%s", c) != EOF) {
		int length = strlen(c);
		int what = 0;
		for (int i = 0; i < length; i++) {
			what+=(c[i] - '0')*pow(10, length - 1 - i);
		}
		if (bt[what] == false) {
			bt.set(what,true);
			printf("%d ", what);
		}
	}
	
	return 0;
}