#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int lefoot, rifoot, allfoot;
int main(){
	scanf("%d%d%d", &lefoot, &rifoot, &allfoot);
	while (allfoot > 0) {
		if (lefoot > rifoot) {
			rifoot++;
			allfoot--;
		}
		else {
			lefoot++;
			allfoot--;
		}
	}
	printf("%d\n", lefoot + rifoot - abs(lefoot - rifoot));
	return 0;
}