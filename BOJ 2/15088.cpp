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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int main() {
	int here = 0;
	int n, k;
	stack<int> st;
	st.push(here);
	scanf(" %d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		string s;
		cin >> s;
		if (s == "undo") {
			int cnt;
			scanf(" %d", &cnt);
			for (int i = 1; i <= cnt; i++) st.pop();
			here = st.top();
		}
		else {
			int wise = stoi(s);
			if (wise > 0) {
				wise %= n;
				here = (here + wise) % n;
				st.push(here);
			}
			else if (wise == 0) {
				st.push(here);
			}
			else {
				int temp = -1 * wise;
				temp %= n;
				temp *= -1;
				wise = temp;
				here += wise;
				if (here < 0) here += n;
				st.push(here);
			}
		}
	}
	printf("%d", st.top());
	return 0;
}