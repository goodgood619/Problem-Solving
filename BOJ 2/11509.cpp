#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int rx[3] = {0,-1,1};
int ry[3] = {1,1,1};
int height[1000005];
int main() {
	int n;
	scanf("%d", &n);
	int arrow = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (height[num + 1] == 0) { // 아직 num+1에 있는 높이가 화살에 맞지 않음
			height[num]++;
			arrow++;
			continue;
		}
		height[num + 1]--; // num+1에 있는 높이가 맞았었기때문에, num도 맞게된다, 그러므로 화살이 필요없다
		height[num]++; // 맞은 타겟은 이제 num의 위치가 된다
	}
	printf("%d\n", arrow);
	return 0;
}

