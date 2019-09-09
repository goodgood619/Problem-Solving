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
stack<double> st;
stack<char> oper;
int n;
int check[26];
int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n; i++) {
		double num;
		scanf("%lf", &num);
		check[i] = num;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			st.push(check[s[i] - 'A']);
		}
		else {
			double second = st.top();
			st.pop();
			double first = st.top();
			st.pop();
			if (s[i] == '+') st.push(first + second);
			if (s[i] == '-') st.push(first - second);
			if (s[i] == '*') st.push(first*second);
			if (s[i] == '/') st.push(first / second);
		}
	}
	printf("%.2lf\n", st.top());
	return 0;
}