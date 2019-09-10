#include <cstdio>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
char s[105];
int main(){
	scanf("%s", s);
	int length = strlen(s);
	stack <int> st;
	for (int i = 0; i <length; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) st.push(s[i] - '0');
		else {
			char what = s[i];
			if (what == '+') {
				int second = st.top();
				st.pop();
				int first = st.top();
				st.pop();
				st.push(first + second);
			}
			else if (what == '-'){
				int second = st.top();
				st.pop();
				int first = st.top();
				st.pop();
				st.push(first-second);
			}
			else if (what == '*') {
				int second = st.top();
				st.pop();
				int first = st.top();
				st.pop();
				st.push(first*second);
			}
			else if (what == '/') {
				int second = st.top();
				st.pop();
				int first = st.top();
				st.pop();
				st.push(first/second);
			}
		}
	}
	printf("%d\n", st.top());
	return 0;
}