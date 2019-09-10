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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int a, b, c, d;
int main() {
	scanf("%d%d%d%d", &a, &b, &c, &d);
	for (int i = 0; i*a <= d; i++) {
		for (int j = 0; j*b <= d; j++) {
			for (int k = 0; k*c <= d; k++) {
				if (a*i + b * j + k * c == d) {
					printf("1\n");
					return 0;
				}
			}
		}
	}
	printf("0\n");
	return 0;
}