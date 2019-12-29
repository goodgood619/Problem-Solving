#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int t;
    scanf("%d",&t);
    while(t--) {
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            printf("%c",tolower(s[i]));
        }
        printf("\n");
    }
    return 0;
}