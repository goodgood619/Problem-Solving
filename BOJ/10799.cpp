#include <cstdio>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;
stack<char> st;
char c[100006];
long long ans;
int main(){
	scanf("%s", c);
	int length = strlen(c);
	int leftcnt = 0;
	for (int i = 0; i < length; i++) {
		char s = c[i];
		if (s == '(') {
			st.push(s);
			leftcnt++;
		}
		else if (s == ')'){
			leftcnt--;
			if (c[i - 1] == '('){
				if(leftcnt>=0)
				ans += leftcnt;
			}
			else ans += 1;
			st.pop();
		}
	}
	printf("%lld\n", ans);
	return 0;
}