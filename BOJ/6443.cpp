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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
vector<int> a;
bool visited[55];
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		do {
			printf("%s\n", s.c_str());
		}while (next_permutation(s.begin(), s.end()));

	}
	return 0;
}