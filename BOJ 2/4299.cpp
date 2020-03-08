#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	double x = (a + b) / 2.0, y = (a - b) / 2.0;
	if (x != (int)x || y != (int)y || x < 0 || y < 0) printf("-1");
	else {
		int a1 = (int)x, a2 = (int)y;
		printf("%d %d\n", a1, a2);
	}
	return 0;
}