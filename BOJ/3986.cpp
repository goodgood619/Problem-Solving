#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;
int n,cnt;
int main(){
	scanf("%d", &n);
	while (n--){
		char c[100001] = {'\0',};
		stack <char> st;
		scanf("%s", c);
		st.push(c[0]);
		int length = strlen(c);
		for (int i = 1; i < length; i++){
			if (st.empty()) {
				st.push(c[i]);
				continue;
			}
			else if (c[i] == st.top()) {
				st.pop();
				continue;
			}
			else if (c[i] != st.top()) {
				st.push(c[i]);
				continue;
			}
		}
		if (st.empty()) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}