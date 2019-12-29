#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(ll n, string &s) {
    if(n<2){
        s.push_back(n +'0');
        return;
    }
    go(n/2,s);
    go(n%2,s);
}
int main() {
    ll n;
    scanf("%lld",&n);
    string s;
    go(n,s);
    ll sum = 0;
    int cnt = 0;
    for(int i=0;i<s.size();i++) {
        sum += (s[i]-'0') * pow(2,cnt);
        cnt++;
    }
    s.clear();
    printf("%lld\n",sum);
    return 0;
}