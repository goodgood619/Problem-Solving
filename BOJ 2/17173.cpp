#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    bool *visited = new bool[1001];
    for(int i=1;i <=1000;i++) visited[i] = false;
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        for(int j= num;j<=n;j+=num) visited[j] = true;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(visited[i]) ans += i;
    }
    printf("%d\n",ans);
    delete[] visited;
    return 0;
}