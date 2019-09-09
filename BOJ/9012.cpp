#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int t;
int main(){
	scanf("%d",&t);
	while (t--) {
		string s;
		cin >> s;
		int length = s.size();
		stack<char> st;
		bool no = false;
		for (int i = 0; i < length; i++) {
			if (s[i] == '(') {
				st.push(s[i]);
			}
			else{
				if (st.empty()) {
					no = true;
					break;
				}
				st.pop();
			}
		}
		if (no || !st.empty()) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}