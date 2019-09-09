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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n;
bool visited[1001][1001];
int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if (s1 == "true" && s3 == "true") {
		printf("true");
	}
	else if (s1 == "true" && s3 == "false") {
		s2 == "OR" ? printf("true") : printf("false");
	}
	else if (s1 == "false" && s3 == "true") {
		s2 == "OR" ? printf("true") : printf("false");
	}
	else {
		printf("false");
	}
	return 0;
}