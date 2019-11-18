#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    string s = "";
    string p = to_string(n);
    for(int i = 0; i<n;i++){
        s.append(p);
    }
    int cnt = 0;
    vector<char> v;
    for(int i = 0;;i++) {
        if(cnt == m) break;
        v.push_back(s[i]);
        cnt++;
    }
    if(s.size()<=m){
        for(int i = 0 ; i<n;i++){
            printf("%s",p.c_str());
        }
    }
    else {
        for(int i =0 ;i<v.size();i++) printf("%c",v[i]);
    }
    return 0;
}