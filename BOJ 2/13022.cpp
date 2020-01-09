#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(int index,string &s, bool &ans) {
    if(ans || index >= s.size()) {
        ans = true;
        return;
    }
    // w연속갯수 세기
    int p = index;
    while(p <s.size() && s[p] == 'w') {
        p++;
    }
    int cnt = p-index;
    if(cnt ==0) return;
    for(int i=0;i<cnt;i++) {
        if(index<s.size() && s[index]=='w') index++;
        else return;
    }
    for(int i=0;i<cnt;i++) {
        if(index<s.size() && s[index]=='o') index++;
        else return;
    }
    for(int i=0;i<cnt;i++) {
        if(index<s.size() && s[index] == 'l') index++;
        else return;
    }
    for(int i=0;i<cnt;i++) {
        if(index<s.size()&& s[index]=='f') index++;
        else return;
    }
    go(index,s,ans);
}
int main() {
    string s;
    cin >> s;
    bool ans = false;
    go(0,s,ans);
    printf("%d\n",ans?1:0);
    return 0;
}