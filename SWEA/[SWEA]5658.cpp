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
#define mod 1000000009
#define lim 1000000000
typedef pair < ll, ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int depth = n / 4;
		string s;
		cin >> s;
		map<string, int> m;
		for (int i = 0; i < depth; i++) {
			int cnt = 0;
			string temp;
			for (int j = 0; j < s.size(); j++) {
				temp.push_back(s[j]);
				cnt++;
				if (cnt == depth) {
					if (m.count(temp) == 0) {
						m[temp] = 1;
					}
					cnt = 0;
					temp.clear();
				}
			}
			s.push_back(s[0]);
			s.erase(s.begin());
		}
		map<string, int>::reverse_iterator it;
		int cnt = 0;
		string ans;
		for (it = m.rbegin(); it != m.rend(); it++){
			cnt++;
			if (cnt == k) {
				ans = it->first;
				break;
			}
		}
		int sum = 0;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] >= 'A' && ans[i] <= 'F') sum += (ans[i] - 55)*pow(16, ans.size() - 1 - i);
			else sum += (ans[i] - '0')*pow(16, ans.size() - 1 - i);
		}
		printf("#%d %d\n", Case++,sum);
	}
	return 0;
}