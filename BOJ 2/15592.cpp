#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int area(int x1, int y1, int x2, int y2) {
	return (x2 - x1)*(y2 - y1);
}
int main() {
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
	if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) { //다포함
		printf("0\n");
		return 0;
	}
	else if (x1 <= x3 && x2 >= x4 && y1 <= y3 && y2 >= y4) { //다포함2
		printf("0\n");
		return 0;
	}
	if (y3 <= y1 && y4 >= y2 && x3 < x2 && x3>x1 && x4 >= x2) { // 동쪽에 부분겹치기
		printf("%d\n", area(x3, y2, x1, y1));
	}
	else if (y3 <= y1 && y4 >= y2 && x4 > x1 && x4 < x2 && x3 <= x1) { //서쪽에 부분겹치기
		printf("%d\n", area(x2, y2, x4, y1));
	}
	else if (x3 <= x1 && x4 >= x2 && y3 < y2 && y3>y1 && y4 >= y2) { // 북쪽에 부분겹치기
		printf("%d\n", area(x2, y3, x1, y1));
	}
	else if (x3 <= x1 && x4 >= x2 && y4 > y1 && y4 < y2 && y3 <= y1) {//남쪽에 부분겹치기
		printf("%d\n", area(x2, y2, x1, y4));
	}
	else {
		printf("%d\n", area(x1, y1, x2, y2));
	}
	return 0;
}