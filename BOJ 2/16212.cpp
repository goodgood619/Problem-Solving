#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[8] = {0,0,-1,1,1,1,-1,-1};
int goy[8] = {1,-1,0,0,-1,1,-1,1};
int main() {
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    return 0;
}