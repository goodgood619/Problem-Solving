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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int a, b;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main(void) {
	scanf("%d%d", &a, &b);
	int c=gcd(a, b);
	vector<int> v;
	for (int i = 1; i <= sqrt(c); i++) {
		if (c%i == 0) {
			if (i != c / i) {
				v.push_back(i);
				v.push_back(c / i);
			}
			else v.push_back(i);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d %d\n", v[i], a / v[i], b / v[i]);
	}

	return 0;
}