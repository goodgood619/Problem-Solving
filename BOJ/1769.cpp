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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
char c[1000005];
int main() {
	scanf("%s",c);
	string s = c;
	int cnt = 0;
	int no = 0;
	int sum = 0;
	while (1) {
		int sum = 0;
		if (s.size() == 1) {
			if (s[0] == '3' || s[0] == '6' || s[0] == '9') {
				break;
			}
			else {
				no = 1;
				break;
			}
		}
		for (int i = 0; i < s.size(); i++) {
			sum += (s[i] - '0');
		}
		string temp = to_string(sum);
		s = temp;
		cnt++;
	}
	no == 0 ? printf("%d\nYES\n", cnt) : printf("%d\nNO\n", cnt);
	return 0;
}