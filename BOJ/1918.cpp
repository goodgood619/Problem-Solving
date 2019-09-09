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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1, -1,0 };
int goy[4] = { 1,0, 0,-1 };
string s;
stack<char> st,oper;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') {
			while (!st.empty()) {
				char c = st.top();
				if (c == '*' || c == '/') {
					printf("%c", st.top());
					st.pop();
				}
				else if (c == '+' || c == '-') {
					if (s[i] == '*' || s[i] == '/') break; //우선순위가 밀림
					printf("%c", st.top());
					st.pop();
				}
				else if (c == '(') break;
			}
			st.push(s[i]);
		}
		else if (s[i] == '(') {
			st.push(s[i]);
			continue;
		}
		else if (s[i] == ')') {
			while (st.top() != '(') {
				printf("%c", st.top());
				st.pop();
			}
			st.pop();
		}
		else {
			printf("%c", s[i]);
		}
	}
	while (!st.empty()) {
		printf("%c", st.top());
		st.pop();
	}
	return 0;
}