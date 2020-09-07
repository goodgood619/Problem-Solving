#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (st.empty()) {
            st.push(s[i]);
            continue;
        }
        char top = st.top();
        char here = s[i];
        if (top != here) st.push(here);
        else {
            if (st.empty()) return 0;
            st.pop();
        }
    }
    if (st.empty()) return 1;
    return 0;
}