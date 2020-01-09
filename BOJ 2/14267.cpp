#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    ll value;
    ll lazy;
};
ll start[100001],last[100001];
void u_lazy(int nodenum,int nodeleft,int noderight,vector<p> &seg) {
    if(seg[nodenum].lazy == 0) return;
    if(nodeleft != noderight) {
        seg[nodenum*2].lazy += seg[nodenum].lazy ;
        seg[nodenum*2+1].lazy += seg[nodenum].lazy;
    }
    seg[nodenum].value += seg[nodenum].lazy *(noderight-nodeleft + 1);
    seg[nodenum].lazy = 0;
}

void dfs(int here,int &person,vector<vector<int>> &v) {
    start[here] = ++person;
    for(int i=0;i<v[here].size();i++) {
        int next = v[here][i];
        dfs(next,person,v);
    }
    last[here] = person;
}
void update(int nodenum,int left,int right,int nodeleft,int noderight, vector<p> &seg, ll value) {
    u_lazy(nodenum,nodeleft,noderight,seg);
    if(nodeleft > right || left > noderight) return;
    else if(left <= nodeleft && noderight <= right) {
        seg[nodenum].lazy += value;
        u_lazy(nodenum,nodeleft,noderight,seg);
        return;
    }
    int mid = (nodeleft + noderight) / 2;
    update(nodenum*2,left,right,nodeleft,mid,seg,value);
    update(nodenum*2+1,left,right,mid+1,noderight,seg,value);
    seg[nodenum].value = seg[nodenum*2].value + seg[nodenum*2+1].value;
}
ll query(int nodenum,int left,int right,int nodeleft,int noderight, vector<p> &seg) {
    u_lazy(nodenum,nodeleft,noderight,seg);
    if(nodeleft > right || left > noderight) return 0;
    else if(left <= nodeleft && noderight <= right) return seg[nodenum].value;
    int mid = (nodeleft + noderight) / 2;
    return query(nodenum*2,left,right,nodeleft,mid,seg) + query(nodenum*2+1,left,right,mid+1,noderight,seg);
}
int main() {
    Int n,m,h = 1,temp,person = 0;
    scanf(" %d%d",&n,&m);
    vector<p> seg;
    while(h<n) h*=2;
    seg.assign(h*2,{0,0});
    vector<vector<int>> v;
    v.assign(n+1,vector<int>());
    scanf(" %d",&temp);
    for(int i=2;i<=n;i++) {
        Int up;
        scanf(" %d",&up);
        v[up].push_back(i);
    }
    dfs(1,person,v);
    for(int i=0;i<m;i++) {
            Int index;
            ll value;
            scanf(" %d%lld",&index,&value);
            update(1,start[index],last[index],1,h,seg,value);
    }
    printf("0 ");
    for(int i=2;i<=n;i++) {
        printf("%lld ",query(1,start[i],start[i],1,h,seg));
    }
    return 0;
}