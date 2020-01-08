#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    ll value;
    ll lazy;
};
void initupdate(int index, ll value,vector<p> &seg,int h) {
    index += h - 1;
    seg[index].value = value;
    while (index > 1) {
        index /= 2;
        seg[index].value = seg[index * 2].value + seg[index * 2 + 1].value;
    }
}
void u_lazy(int nodenum,int nodeleft,int noderight,vector<p> &seg) {
    if(seg[nodenum].lazy == 0 ) return;
    seg[nodenum].value += (noderight-nodeleft + 1) * seg[nodenum].lazy;
    if(nodeleft != noderight) {
        seg[nodenum*2].lazy +=seg[nodenum].lazy;
        seg[nodenum*2+1].lazy +=seg[nodenum].lazy;
    }
    seg[nodenum].lazy = 0;
}
void update(int nodenum,int left,int right,int nodeleft,int noderight,ll value, vector<p> &seg) {
    u_lazy(nodenum,nodeleft,noderight,seg);
    if(nodeleft > right || left > noderight) return;
    else if(left<=nodeleft && noderight <= right) {
        seg[nodenum].lazy += value;
        u_lazy(nodenum,nodeleft,noderight,seg);
        return;
    }
    int mid = (nodeleft+noderight) / 2;
    update(nodenum*2,left,right,nodeleft,mid,value,seg);
    update(nodenum*2+1,left,right,mid+1,noderight,value,seg);
    seg[nodenum].value = seg[nodenum*2].value + seg[nodenum*2+1].value;
}
ll query(int nodenum,int left,int right,int nodeleft,int noderight,vector<p> &seg) {
    u_lazy(nodenum,nodeleft,noderight,seg);
    if(nodeleft > right || left > noderight) return 0;
    else if(left <= nodeleft && noderight <= right) return seg[nodenum].value;
    int mid = (nodeleft+noderight) / 2;
    return query(nodenum*2,left,right,nodeleft,mid,seg) + query(nodenum*2+1,left,right,mid+1,noderight,seg);
}
int main() {
    Int n,m,k,h=1;
    scanf("%d%d%d",&n,&m,&k);
    vector<p> seg;
    while(h<n) h*=2;
    seg.assign(h*2,{0,0});
    for(int i=1;i<=n;i++){
        ll value;
        scanf("%lld",&value);
        initupdate(i,value,seg,h);
    }
    for(int i=0;i<m+k;i++) {
        Int a;
        scanf("%d",&a);
        if(a == 1) {
            Int left,right;
            ll value;
            scanf("%d%d%lld",&left,&right,&value);
            update(1,left,right,1,h,value,seg);
        }
        else {
            Int left,right;
            scanf("%d%d",&left,&right);
            printf("%ld\n",query(1,left,right,1,h,seg));
        }
    }
    return 0;
}