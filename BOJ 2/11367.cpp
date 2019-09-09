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
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		int a;
		cin >> s >> a;
		if (a >= 97 && a <= 100) printf("%s A+\n", s.c_str());
		else if (a >= 90 && a <= 96) printf("%s A\n", s.c_str());
		else if(a>=87 && a<=89) printf("%s B+\n", s.c_str());
		else if (a >= 80 && a <= 86) printf("%s B\n", s.c_str());
		else if (a >= 77 && a <= 79) printf("%s C+\n", s.c_str());
		else if (a >= 70 && a <= 76) printf("%s C\n", s.c_str());
		else if (a >= 67 && a <= 69) printf("%s D+\n", s.c_str());
		else if (a >= 60 && a <= 66) printf("%s D\n", s.c_str());
		else printf("%s F\n", s.c_str());
	}
	return 0;
}