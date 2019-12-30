#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    vector<int> item;
    item.assign(n+1,0);
    for(int i=1;i<=n;i++) {
        Int num;
        scanf("%d",&num);
        item[i] = num;
    }
    bool *visited = new bool[n+1];
    for(int i=0;i<=n;i++) visited[i] = false;
    int** dist = new int*[n+1];
    for(int i=0;i<=n;i++) dist[i] = new int[n+1];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++){
            if(i ==j ){
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = 1e9;
        }
    }
    for(int i=0;i<r;i++) {
        Int here,next,cost;
        scanf("%d%d%d",&here,&next,&cost);
        dist[here][next] = min(dist[here][next],cost);
        dist[next][here] = min(dist[next][here],cost);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++){
                if(dist[i][j]> dist[i][k] +dist[k][j])
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans =0 ;
    for(int i=1;i<=n;i++) {
        int temp = 0;
        for(int j=1;j<=n;j++) {
            if(dist[i][j]<=m) temp += item[j];
        }
        ans = max(ans,temp);
    }
    printf("%d\n",ans);
    return 0;
}