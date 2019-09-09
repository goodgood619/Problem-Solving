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
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
bool visited[105];
int main() {
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size();) {
		if (s[i] == ' ') {
			i++;  continue;
		}
		else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			visited[i + 1] = true;
			visited[i + 2] = true;
			i += 3;
		}
		else i++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (!visited[i]) printf("%c", s[i]);
	}
	return 0;
}