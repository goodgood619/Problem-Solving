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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
map<string, int> m;
map<int, string> m2;
int main() {
	int a, b;
	m2[1] = "one", m2[2] = "two", m2[3] = "three", m2[4] = "four", m2[5] = "five", m2[6] = "six", m2[7] = "seven", m2[8] = "eight", m2[9] = "nine",m2[0]="zero";
	m["one"] = 1, m["two"] = 2, m["three"] = 3, m["four"] = 4, m["five"] = 5, m["six"] = 6, m["seven"] = 7, m["eight"] = 8, m["nine"] = 9,m["zero"]=0;
	scanf("%d%d", &a, &b);
	vector<pair<string, int>> v;
	for (int i = a; i <= b; i++) {
		if (i >= 10) {
			string t = m2[i / 10];
			t.append(m2[i % 10]);
			v.push_back({ t,i });
		}
		else {
			v.push_back({ m2[i], m[m2[i]]});
		}
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cnt == 9) {
			printf("%d\n", v[i].second);
			cnt = 0;
		}
		else {
			printf("%d ", v[i].second);
			cnt++;
		}
	}
	return 0;
}