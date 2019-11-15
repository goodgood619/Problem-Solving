#include <bits/stdc++.h>
using namespace std;
struct pos{
    int here;
    int dist;
};
void go(queue<pos> &q, int *visited,int &here,int &dist){
    if(here>=0 && here<=100000 && !visited[here]){
        visited[here] = 1;
        q.push({here,dist+1});
    }
}
int bfs(int a,int b,int n,int m){
    int *visited = new int[100002];
    for(int i = 0; i<= 100000;i++) visited[i] = 0;
    visited[n] = 1;
    queue<pos> q;
    q.push({n,0});
    int ans = 1e9;
    while(!q.empty()) {
        int here = q.front().here;
        int dist = q.front().dist;
        if(here == m){
            ans = min(ans,dist);
            break;
        }
        q.pop();
        int nx = here+1, ny = here-1,na = here+a, nb = here+b, mna = here-a, mnb = here-b,ga = here*a, gb = here*b;
        go(q,visited,nx,dist);
        go(q,visited,ny,dist);
        go(q,visited,na,dist);
        go(q,visited,nb,dist);
        go(q,visited,mna,dist);
        go(q,visited,mnb,dist);
        go(q,visited,ga,dist);
        go(q,visited,gb,dist);

    }
    return ans;
}

int main() {
    int a,b,n,m;
    scanf("%d%d%d%d",&a,&b,&n,&m);
    printf("%d\n",bfs(a,b,n,m));
    return 0;
}