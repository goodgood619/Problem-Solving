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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
int main() {
	setbuf(stdout, NULL);
	string s;
	cin >> s;
	if (s.size() == 1) {
		printf("%s", s.c_str());
	}
	else {
		int num = stoi(s);
		int len = 1;
		while (true) {
			if (num > pow(10, len)) {
				int MOD = pow(10, len);
				if (num%MOD>= 5 * pow(10, len - 1)) {
					num += (pow(10,len)-num%MOD);
					len++;
				}
				else {
					num -= num % MOD;
					len++;
				}
			}
			else break;
		}
		printf("%d\n", num);
	}
	return 0;
}
