#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <string.h>
using namespace std;
int n;
int isprime[10005];
int stx, sty, enx, eny;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> pq;
int dist[10005];
vector<P> temp;
vector<vector<P>> a;
#define INF 99999999
stack<char> st;
int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s[0] == '.') break;
		int length = s.size();
		stack<char> st;
		bool check = false;
		for (int i = 0; i < length; i++) {
			if (s[i] == '(' || s[i] == '[') st.push(s[i]);
			else if (s[i] == ')' || s[i] == ']') {
				if (st.empty()) {
					check = true;
					break;
				}
				if (st.top() == '(' && s[i] == ']') {
					check = true;
					break;
				}
				else if (st.top() == '[' && s[i] == ')') {
					check = true;
					break;
				}
				st.pop();
			}
		}
		if (check || !st.empty()) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}