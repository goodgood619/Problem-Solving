#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++) {
        if(i % 10 == 0 && i>=10) printf("\n");
        printf("%c",s[i]);
    }
    return 0;
}