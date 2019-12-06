#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int value = gcd(a,b);
    vector<int> v;
    for(int i=1;i<=sqrt(value);i++){
        if(value % i == 0){
            if(i != value / i){
                v.push_back(i);
                v.push_back(value/i);
            }
            else {
                v.push_back(i);
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        printf("%d %d %d\n",v[i],a/v[i],b/v[i]);
    }

    return 0;
}