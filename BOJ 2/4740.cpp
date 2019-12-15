#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    while(true) {
        string s;
        getline(cin,s);
        if(s == "***") break;
        for(int i=s.size()-1;i>=0;i--) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}