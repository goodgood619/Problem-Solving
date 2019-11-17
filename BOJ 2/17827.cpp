#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
int main() {
    int n,m,v;
    scanf("%d%d%d",&n,&m,&v);
    v--;
    vector<int> graph;
    graph.assign(n+1,0);
    for(int i = 0 ; i < n ;i++) {
        scanf(" %d", &graph[i]);
    }
    for(int i = 0 ; i<m ;i++){
        int k;
        scanf("%d",&k);
        if(k<=v) {
            printf("%d\n",graph[k]);
        }
        else {
            int mod = n-v;
            printf("%d\n",graph[(k-v)%mod+v]);
        }
    }
    graph.clear();
    return 0;
}