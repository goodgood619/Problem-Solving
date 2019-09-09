#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--){
		vector <char> cc;
		char s[1000005] = { '\0', };
		scanf("%s", s);
		int length = strlen(s);
		stack <char> st;
		stack <char> temp;
		for (int i = 0; i < length; i++) {
			if (st.empty()&&temp.empty()&& (s[i] == '<' || s[i] == '>' || s[i]=='-')) continue;
			else{
				if (s[i] != '<' && s[i] != '>' && s[i] != '-'){
						st.push(s[i]);
						continue;
				}
				else {
					if (s[i] == '>' && temp.empty()) continue;
					else if (s[i] == '>' && !temp.empty()) {
						char TT=temp.top();
						temp.pop();
						st.push(TT);
						continue;
					}
					if (s[i] == '<'){
						if (st.empty()) continue;
						char tt = st.top();
						st.pop();
						temp.push(tt);
					}
					if (s[i] == '-'){
						if (st.empty()) continue;
						st.pop();
					}
				}
			}
		}
		while (!temp.empty()) {
			char TT = temp.top();
			temp.pop();
			st.push(TT);
		}
		while (!st.empty()) {
			cc.push_back(st.top());
			st.pop();
		}
		for (int i = cc.size()-1;i >= 0; i--) {
			printf("%c", cc[i]);
		}
		printf("\n");
	}
	return 0;
}