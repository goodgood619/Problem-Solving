#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
int cow[105];
int n;
int go(int cur,bool check){
	int lastindex = cur;
	int radius = 1;
	int direction = 0;
	while (lastindex>= 1 && lastindex <= n){
		if (!check) direction = -1;
		else direction = 1;
		int nextindex = lastindex;
		while (nextindex + direction >= 1 && nextindex + direction <= n && abs(cow[nextindex+direction]-cow[lastindex])<=radius){
			nextindex += direction;
		}
		if (nextindex == lastindex) break;
		lastindex = nextindex;
		radius++;
	}
	return lastindex;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &cow[i]);
	}
	sort(cow + 1, cow + n + 1);
	int Max = 1;
	for (int i = 1; i <= n; i++){
		int leftmostindex=go(i, false);
		int rightmostindex=go(i, true);
		Max = max(Max, rightmostindex - leftmostindex+1);
	}
	printf("%d\n", Max);
	return 0;
}