#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    Int value;
    Int lazy;
};
void u_lazy(int nodenum,int nodeleft,int noderight,vector<p> &seg) {
    if(seg[nodenum].lazy == 0) return;
    seg[nodenum].value = (noderight-nodeleft+1)-seg[nodenum].value;
    if(nodeleft != noderight) {
        seg[nodenum*2].lazy = !seg[nodenum*2].lazy;
        seg[nodenum*2+1].lazy = !seg[nodenum*2+1].lazy;
    }
    seg[nodenum].lazy = 0;
}
void update(int nodenum,int left,int right,int nodeleft,int noderight, vector<p> &seg) {
    u_lazy(nodenum,nodeleft,noderight,seg);
    if(nodeleft > right || left > noderight) return;
    else if(left <= nodeleft && noderight <= right) {
        seg[nodenum].lazy = !seg[nodenum].lazy;
        u_lazy(nodenum,nodeleft,noderight,seg);
        return;
    }
    int mid = (nodeleft+noderight) /2;
    update(nodenum*2,left,right,nodeleft,mid,seg);
    update(nodenum*2+1,left,right,mid+1,noderight,seg);
    seg[nodenum].value = seg[nodenum*2].value + seg[nodenum*2+1].value;
}
Int query(int nodenum,int left,int right,int nodeleft,int noderight,vector<p> &seg) {
    u_lazy(nodenum,nodeleft,noderight,seg);
    if(nodeleft >right || left > noderight) return 0;
    else if(left<=nodeleft && noderight <= right) return seg[nodenum].value;
    int mid = (nodeleft+noderight) /2;
    return query(nodenum*2,left,right,nodeleft,mid,seg) + query(nodenum*2+1,left,right,mid+1,noderight,seg);
}
int main() {
    Int n,m,h=1;
    scanf("%d%d",&n,&m);
    vector<p> seg;
    while(h<n) h*=2;
    seg.assign(h*2,{0,0});
    for(int i=0;i<m;i++) {
        Int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 0 ) {
            update(1,b,c,1,h,seg);
        } else {
            printf("%d\n",query(1,b,c,1,h,seg));
        }
    }
    return 0;
}