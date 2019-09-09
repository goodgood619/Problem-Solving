
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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int main() {
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	int num = 666, cnt = 1;
	while (1) {
		if (cnt == n) break;
		num++;
		string s = to_string(num);
		int temp = stoi(s);
		int six = 0;
		while (temp) {
			int sk = temp % 10;
			if (sk == 6) six++;
			else if (six < 3) six = 0;
			temp /= 10;
		}
		if (six >= 3) cnt++;
	}
	printf("%d\n", num);
	return 0;
}