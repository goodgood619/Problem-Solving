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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int,char>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n;
int number[501];
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int num = i;
		int p = 2;
		while (num != 1) {
			if (num%p == 0) {
				num /= p;
				number[p]++;
				p = 2;
			}
			else p++;
		}
	}
	printf("%d\n", min(number[2], number[5]));
	return 0;
}