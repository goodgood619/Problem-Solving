#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
struct pos{
    int next;
    ll cost;
};
void dfs(int here,vector<vector<pos>> &v,ll cost,bool *visited,ll &ans){
    visited[here] = true;
    ans= max(ans,cost);
    for(int i=0;i<v[here].size();i++){
        int next = v[here][i].next;
        ll nextcost = v[here][i].cost;
        if(!visited[next]){
            dfs(next,v,cost+nextcost,visited,ans);
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    vector<vector<pos>> v;
    v.assign(n+1,vector<pos>());
    for(int i=1;i<n;i++){
        int a,b;
        ll c;
        scanf("%d%d%lld",&a,&b,&c);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    bool *visited = new bool[n+1];
    for(int i=1;i<=n;i++) visited[i] = false;
    ll ans = 0;
    dfs(1,v,0,visited,ans);
    printf("%lld\n",ans);
    delete[] visited;
    return 0;
}