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
int main() {
	char c[105] = { '\0', };
	scanf("%s", c);
	string s = c;
	string t;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			sum += stoi(t);
			t.clear();
		}
		else t.push_back(s[i]);
	}
	sum += stoi(t);
	t.clear();
	printf("%d\n", sum);
	return 0;
}