#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    vector<int> v;
    for(int i=3;i<=3000;i+=3) {
        v.push_back(i);
    }
    Int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i=0;i<v.size();i++ ){
        for(int j=0;j<v.size();j++) {
            Int p = n - v[i]-v[j];
            if(p>0 && p%3 == 0) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}