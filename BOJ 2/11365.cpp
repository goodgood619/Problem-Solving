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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
	while (1) {
		char s[505] = { '\0', };
		scanf(" %[^\n]s", s);
		if (!strcmp(s, "END")) break;
		int length = strlen(s);
		for (int i = length - 1; i >= 0; i--) printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}