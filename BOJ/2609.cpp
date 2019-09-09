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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int a, b;
int main() {
	scanf("%d%d", &a, &b);
	int Min = 1;
	int m = 2;
	int p = a, q = b;
	while (1) {
		if (m > min(a, b)) break;
		if (a%m == 0 && b%m == 0) {
			a /= m, b /= m;
			Min *= m;
			m = 2;
		}
		else m++;
	}
	printf("%d\n%d\n", Min, p / Min * q);
	return 0;
}