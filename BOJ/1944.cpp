#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
struct pos{
    int x;
    int y;
    int dist;
};
struct pos2{
    int here;
    int next;
    int dist;
};
struct cmp{
    bool operator()(pos2 a,pos2 b){
        if(a.dist != b.dist) return a.dist> b.dist;
        if(a.here != b.here) return a.here > b.here;
        if(a.next != b.next) return a.next > b.next;
    }
};
void bfs(pos &a,int st, char **board,int n,vector<pos> &v,priority_queue<pos2,vector<pos2>,cmp> &pq) {
    vector<pos> temp;
    int x= a.x, y = a.y;
    bool **visited = new bool*[n];
    for(int i = 0;i < n ;i++) visited[i] = new bool[n];
    for(int i=0;i < n; i++) {
        for(int j=0 ;j < n; j++) {
            visited[i][j] = false;
        }
    }
    visited[x][y] = true;
    queue<pos> q;
    q.push({x,y,0});
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().dist;
        q.pop();
        for(int i =0 ;i<4;i++) {
            int nx = x+gox[i], ny = y+goy[i];
            if(nx < 0 || nx>=n || ny<0 || ny>=n || board[nx][ny] =='1' || visited[nx][ny]) continue;
            else {
                visited[nx][ny] = true;
                if(board[nx][ny] == 'S' || board[nx][ny] == 'K') {
                    int idx = -1;
                    for(int j =0 ;j<v.size();j++){
                        if(nx == v[j].x && ny == v[j].y) {
                            idx = j;
                            break;
                        }
                    }
                    pq.push({st,idx,dist+1});
                }
                q.push({nx,ny,dist+1});
            }
        }
    }
    for(int i = 0 ;i < n;i++) delete[] visited[i];
    delete[] visited;
}
int find(int u,int *parent){
    if(u == parent[u]) return parent[u];
    return parent[u] = find(parent[u],parent);
}
void uni(int u,int v,int *parent){
    u = find(u,parent);
    v = find(v,parent);
    if(u == v) return;
    parent[u] = v;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<pos> v;
    char **board = new char*[n];
    for(int i = 0 ; i<n;i++) board[i] = new char[n];
    for(int i = 0 ;i < n;i++){
        for(int j =0 ;j<n;j++){
            scanf(" %c",&board[i][j]);
            if(board[i][j] == 'S' || board[i][j] == 'K'){
                    v.push_back({i,j,0});
            }
        }
    }
    priority_queue<pos2,vector<pos2>,cmp> pq;
    for(int i =0 ;i<v.size();i++){
        bfs(v[i],i,board,n,v,pq);
    }

    int cnt = 0;
    int ans = 0;
    int *parent = new int[(int)v.size()];
    for(int i = 0 ;i<v.size();i++) parent[i] = i;
    while(!pq.empty()) {
        int here = pq.top().here;
        int next = pq.top().next;
        int dist = pq.top().dist;
        pq.pop();
        int heretop = find(here,parent), nexttop = find(next,parent);
        if(heretop != nexttop){
            uni(here,next,parent);
            ans += dist;
            cnt++;
        }
    }
    cnt == v.size()-1 ? printf("%d\n",ans) : printf("-1\n");
    delete[] parent;
    v.clear();
    for(int i = 0;i<n;i++) delete[] board[i];
    delete[] board;
    return 0;
}