#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};

int main() {
    int t;
    scanf("%d",&t);
    int cnt = 1;
    while(t--) {
        string s;
        cin >> s;
        for(int i =0 ;i<s.size();i++){
            s[i]++;
            if(s[i]>'Z') s[i] = 'A';
        }
        printf("String #%d\n%s\n\n",cnt++,s.c_str());
    }
    return 0;
}