#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
string s1, s2;
int main() {
	cin >> s1 >> s2;
	int gob = s1.size()*s2.size();
	int mod1 = gob / s1.size();
	int mod2 = gob / s2.size();
	string temp1, temp2;
	for (int i = 0; i < mod1; i++) {
		temp1.append(s1);
	}
	for (int i = 0; i < mod2; i++) {
		temp2.append(s2);
	}
	temp1 == temp2 ? printf("1\n") : printf("0\n");
 	return 0;
}