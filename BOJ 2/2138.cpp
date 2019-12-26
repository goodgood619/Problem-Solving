#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(string &s,string &des,int index,int cnt,int &ans) {
    if(index == s.size()-1) {
        if(s[index-1] == des[index-1] && s[index] == des[index]) ans = min(ans,cnt);
        for(int i= index-1;i<=index;i++) {
            s[i] == '0' ? s[i] = '1' : s[i] = '0';
        }
        if(s[index-1] == des[index-1] && s[index] == des[index]) ans = min(ans,cnt+1);
        return;
    }
    if(s[index-1] == des[index-1]) go(s,des,index+1,cnt,ans);
    for(int i = index-1;i<=index+1;i++){
        s[i] == '0' ? s[i] = '1' : s[i] = '0';
    }
    if(s[index-1] == des[index-1]) go(s,des,index+1,cnt+1,ans);
}
int main() {
    string s1,des,s2;
    Int n;
    cin >> n >> s1 >> des;
    Int ans = 1e9;
    s2 = s1;
    for(int i=0;i<=1;i++) {
        s2[i] =='0' ? s2[i] = '1' : s2[i] = '0';
     }
    go(s1,des,1,0,ans);
    go(s2,des,1,1,ans);
    printf("%d\n",ans==1e9?-1:ans);
    return 0;
}