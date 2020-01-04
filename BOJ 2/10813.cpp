#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void Swap(vector<int> &v,Int a,Int b) {
    Int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
int main() {
    Int n,m;
    scanf("%d%d",&n,&m);
    vector<int> v;
    v.assign(n+1,0);
    for(int i=1;i<=n;i++) {
        v[i] = i;
    }
    for(int i=0;i<m;i++) {
        Int a,b;
        scanf("%d%d",&a,&b);
        Swap(v,a,b);
    }
    for(int i=1;i<=n;i++) {
        printf("%d ",v[i]);
    }
    return 0;
}