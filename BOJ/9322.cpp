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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int t, n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		string s1[1005],s2[1005],password[1005],ans[1005];
		for (int i = 0; i < n; i++) {
			cin >> s1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> s2[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> password[i];
		}
		int num[1005] = { 0, };
		for (int i = 0; i <n; i++) {
			string here = s1[i];
			for (int j = 0; j < n; j++) {
				string next = s2[j];
				if (here == next) {
					num[i] = j;
					break;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			ans[i] = password[num[i]];
		}
		for (int i = 0; i < n; i++) {
			printf("%s ", ans[i].c_str());
		}
		printf("\n");
	}
	return 0;
}