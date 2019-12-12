#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void dfs(Int here, vector<vector<Int>> &graph,int* &parent) {
    for(auto i : graph[here]) {
        if(parent[here] == i) continue;
        parent[i] = here;
        dfs(i,graph,parent);
    }
}
int main() {
    Int n;
    scanf("%d",&n);
    vector<vector<Int>> graph;
    graph.assign(n+1,vector<Int>());
    int *parent = new int[n+1];
    for(int i=1;i<=n;i++) parent[i] = 0;
    for(int i=0;i<n-1;i++){
        Int here,next;
        scanf("%d%d",&here,&next);
        graph[here].push_back(next);
        graph[next].push_back(here);
    }
    dfs(1,graph,parent);
    stack<Int> st;
    for(int i=0;i<n;i++){
        Int num;
        scanf("%d",&num);
        if(i>=1 ) {
            for (;;) {
                if (st.empty()) {
                    printf("0\n");
                    return 0;
                }
                if (st.top() != parent[num]) {
                    st.pop();
                } else break;
            }
        }
        st.push(num);
    }
    printf("1");
    delete[] parent;

    return 0;
}