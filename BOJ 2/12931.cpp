#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(vector<int> &v,vector<int> &v2,int dist,int &ans) {
    if(ans != 1e9) return;
    if(v == v2){
        ans = min(ans,dist);
        return;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]>v2[i]) return;
    }
    for(int j=0;j<2;j++) {
        if(j ==0 ) {
            for (int i = 0; i < v2.size(); i++) {
                if (v2[i] % 2 == 1) {
                    v2[i]--;
                    dfs(v, v2, dist + 1, ans);
                    v2[i]++;
                }
            }
        }
        else {
            for (int i = 0; i < v2.size(); i++) {
                v2[i] /= 2;
            }
            dfs(v, v2, dist + 1, ans);
            for (int i = 0; i < v2.size(); i++) {
                v2[i] *= 2;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> v,v2;
    v.assign(n,0);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v2.push_back(num);
    }
    int ans = 1e9;
    dfs(v,v2,0,ans);
    printf("%d\n",ans);
    return 0;
}