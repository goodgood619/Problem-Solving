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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
string s;
void go(int x, int y,int width,int index, int depth) {
	if (index == depth) {
		printf("%d %d %d\n", s.size(), x, y);
		exit(0);
		return;
	}
	if (s[index] == '0') go(x, y, width / 2, index + 1, depth);
	if (s[index] == '1') go(x+width, y, width / 2, index + 1, depth);
	if (s[index] == '2') go(x, y+width, width / 2, index + 1, depth);
	if (s[index] == '3') go(x + width, y + width, width / 2, index + 1, depth);
}
int main() {
	cin >> s;
	go(0, 0,pow(2,s.size()-1),0, s.size());
	return 0;

}
