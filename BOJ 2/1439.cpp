#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    string s;
    cin >> s;
    Int one = 0 , zero = 0;
    s[0] == '0' ? zero++ : one++;
    for(int i=1;i<s.size();i++) {
        if(s[i] != s[i-1]) {
            s[i] == '0' ? zero++ : one++;
        }
    }
    printf("%d\n",zero>one?one:zero);
    return 0;
}