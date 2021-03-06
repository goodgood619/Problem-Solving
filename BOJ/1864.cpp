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
	map<char, int> m;
	m['-'] = 0,m[92]=1,m['(']=2,m['@']=3,m['?']=4,m['>']=5,m['&']=6,m['%']=7,m['/']=-1;
	while (1) {
		string s;
		cin >> s;
		if (s[0] == '#' && s.size() == 1) break;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			sum+=m[s[i]]*pow(8, s.size() - 1 - i);
		}
		printf("%d\n", sum);
	}
	return 0;
}