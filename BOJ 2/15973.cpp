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
int p[5];
int q[5];
int main(){
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &q[i]);
	}
	if (p[1] == q[3] && p[2] == q[4] || p[1] == q[3] && p[4] == q[2] || p[3] == q[1] && p[4] == q[2] || p[3] == q[1] && p[2] == q[4]) printf("POINT\n");
	else if (p[3] < q[1] || p[4] < q[2] || q[3] < p[1] || q[4] < p[2]) printf("NULL\n");
	else if (p[1] == q[3] || p[2] == q[4] || p[3] == q[1] || p[4] == q[2]) printf("LINE\n");
	else printf("FACE\n");
	return 0;
}