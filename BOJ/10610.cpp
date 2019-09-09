
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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
string s;
int check[10];
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		check[s[i] - '0']++;
	}
	if (check[0] == 0) {
		printf("-1\n");
	}
	else {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += i*check[i];
		}
		if (sum % 3 != 0) printf("-1\n");
		else {
			for (int i = 9; i >= 0; i--) {
				while (check[i] != 0) {
						printf("%d", i);
						check[i]--;
				}
			}
		}
	}
	return 0;
}