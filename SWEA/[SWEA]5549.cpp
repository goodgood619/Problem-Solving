#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <functional>
#include <deque>
#include <math.h>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
#define INF 1e9
typedef pair<int, int> P;
int main(){
	int t;
	int Case = 1;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int last = s[s.size() - 1] - '0';
		if (last % 2 == 0) printf("#%d Even\n", Case);
		else printf("#%d Odd\n", Case);
		Case++;
	}

	return 0;
}