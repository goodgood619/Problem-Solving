#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int main() {
    int n;
    scanf("%d",&n);
    vector <int> v;
    for(int i = 0; i<n ; i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    int ans = n;
    for(int i = 0 ;i<v.size();i++){
        ans = min(ans,v[i]+n-i-1);
    }
    printf("%d\n",ans);
    return 0;
}