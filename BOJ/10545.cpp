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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n, m;
string phone[9] = { "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
int origin[9];
int main() {
	for (int i = 0; i < 9; i++) {
		int num;
		scanf("%d", &num);
		origin[i] = num - 1;
	}
	string s;
	cin >> s;
	int idx = -1;
	for (int i = 0; i < s.size(); i++) {
		int same = -1;
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < phone[j].size(); k++) {
				if (s[i] == phone[j][k]) {
					same = j;
					break;
				}
			}
			if (same != -1) break;
		}
		int same2 = 0;
		for (int i = 0; i < 9; i++) {
			if (origin[i] == same) {
				same2 = i;
				break;
			}
		}
		if (idx == same2) {
			printf("#");
			int cnt = 1;
			for (int k = 0; k < phone[same].size(); k++) {
				if (phone[same][k] != s[i]) cnt++;
				else break;
			}
			for (int k = 1; k <= cnt; k++) printf("%d", same2 + 1);
			idx = same2;
		}
		else {
			int cnt = 1;
			for (int k = 0; k < phone[same].size(); k++) {
				if (phone[same][k] != s[i]) cnt++;
				else break;
			}
			for (int k = 1; k <= cnt; k++) printf("%d", same2 + 1);
			idx = same2;
		}
	}
	return 0;
}