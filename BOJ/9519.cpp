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
int x;
string s;
int main() {
	scanf("%d", &x);
	cin >> s;
	int length = s.size();
	if (length % 2 == 0) {
		int cnt = 0;
		string temp[1005];
		temp[cnt] = s;
		while (1) {
			string t = temp[cnt];
			string temp2;
			for (int i = 0; i <t.size(); i += 2) {
				temp2.push_back(t[i]);
			}
			for (int i = t.size() - 1; i >= 0; i -= 2) {
				temp2.push_back(t[i]);
			}
			cnt++;
			temp[cnt] = temp2;
			if (temp2 == s) {
				break;
			}
		}
		printf("%s\n", temp[x%cnt].c_str());
	}
	else {
		int cnt = 0;
		string temp[1005];
		temp[cnt] = s;
		while (1) {
			string t = temp[cnt];
			string temp2;
			for (int i = 0; i <t.size(); i += 2) {
				temp2.push_back(t[i]);
			}
			for (int i = t.size() - 2; i >= 0; i -= 2) {
				temp2.push_back(t[i]);
			}
			cnt++;
			temp[cnt] = temp2;
			if (temp2 == s) {
				break;
			}
		}
		printf("%s\n", temp[x%cnt].c_str());
	}
	return 0;
}