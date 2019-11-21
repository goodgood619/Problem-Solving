#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
struct pos{
    int num;
    int dist;
};
void bfs(int n,int k,string s,int &ans){
    bool *visited = new bool[1000001];
    for(int i=0;i<=1000000;i++) visited[i] = false;
    queue<pos> q;
    q.push({n,0});
    visited[n] = true;
    while(!q.empty()) {
        for(int i=0;i<=1000000;i++) visited[i] = false;
        int size = q.size();
        for(int i=0;i<size;i++) {
            int num = q.front().num;
            int dist = q.front().dist;
            q.pop();
            if(dist == k){
                ans = max(ans,num);
                continue;
            }
            string here = to_string(num);
            for (int j = 0; j < here.size(); j++) {
                for (int k = j + 1; k < here.size(); k++) {
                    string p = here;
                    swap(p[j], p[k]);
                    if (!visited[atoi(p.c_str())] && p[0] != '0') {
                        visited[atoi(p.c_str())] = true;
                        q.push({atoi(p.c_str()), dist + 1});
                    }
                }
            }
        }
    }
    delete[] visited;
}
int main() {
    int n,k,ans = 0;
    scanf("%d%d",&n,&k);
    string s = to_string(n);
    bfs(n,k,s,ans);
    ans == 0? printf("-1\n"):printf("%d\n",ans);
    return 0;
}