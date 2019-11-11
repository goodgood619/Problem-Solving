#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
bool check(int choose,int &n,bool *visited,int **friendcheck){
    for(int i = 1; i<= n ; i++){
        if(visited[i]){
            if(!friendcheck[i][choose]) return false;
        }
    }
    return true;
}
void go(int here,int cnt,int &depth,int &n,int &ans,bool *visited,int **friendcheck) {
    if(ans) return;
    if(cnt == depth){
        for(int i = 1; i <= n ;i++){
            if(visited[i]) printf("%d\n",i);
        }
        ans = 1;
        return;
    }
    for(int i = here + 1 ;i <= n ; i++) {
        if(friendcheck[here][i] == 0) continue;
        if(!visited[i] && check(i,n,visited,friendcheck)) {
            visited[i] = true;
            go(i,cnt+1,depth,n,ans,visited,friendcheck);
            visited[i]= false;
        }
    }
}
int main() {
    int k,n,f;
    scanf("%d%d%d",&k,&n,&f);
    int **friendcheck = new int*[n+1];
    int *frcnt = new int[n+1];
    bool *visited = new bool[n+1];
    int ans = 0;
    for(int i = 1 ; i<= n ; i++) friendcheck[i] = new int[n+1];
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            friendcheck[i][j] = 0;
        }
    }
    for(int i = 1 ; i<=n ;i++){
        frcnt[i] = 0;
        visited[i] = false;
    }
    for(int i = 0 ;i<f;i++){
        int a1,a2;
        scanf("%d%d",&a1,&a2);
        friendcheck[a1][a2] = 1;
        friendcheck[a2][a1] = 1;
        frcnt[a1]++,frcnt[a2]++;
    }

    for(int i = 1; i<=n;i++){
        if(frcnt[i] < k-1) continue;
        visited[i] = true;
        go(i,1,k,n,ans,visited,friendcheck);
        visited[i] = false;
    }
    if(ans == 0)printf("-1\n");
    delete[] frcnt;
    delete[] visited;
    for(int i = 1; i<=n ; i++) delete[] friendcheck[i];
    delete[] friendcheck;
    return 0;
}