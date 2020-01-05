#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,ans = 0;
    string s;
    scanf("%d",&n);
    cin >> s;
    for(int i=0;i<s.size()-3;i++) {
        if(s[i] == 'p' && s[i+1]=='P' && s[i+2] =='A' && s[i+3]=='p') {
            ans++;
            i+=3;
        }
    }
    printf("%d\n",ans);
    return 0;
}