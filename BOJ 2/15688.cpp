#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i=1;i<=n;i++) {
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(auto it : v) printf("%d\n",it);
    return 0;
}