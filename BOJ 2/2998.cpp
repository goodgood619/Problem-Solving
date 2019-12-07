#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin >> s;
    if(s.size() % 3== 1) s = "00" + s;
    else if(s.size()%3 ==2) s= "0" + s;
    int len = s.size()/3;
    for(int i=0;i<len;i++){
        printf("%d",4*(s[i*3]-'0')+2*(s[i*3+1]-'0')+(s[i*3+2]-'0'));
    }
    return 0;
}