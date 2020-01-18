#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    string s[n];
    int first =0;
    for(int i=0;i<m;i++) {
        first==0?s[0].push_back('*'):s[0].push_back('.');
        first==0?first =1 : first =0;
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]=='*') s[i+1].push_back('.');
            else s[i+1].push_back('*');
        }
    }
    for(int i=0;i<n;i++) {
        printf("%s\n",s[i].c_str());
    }
    return 0;
}
