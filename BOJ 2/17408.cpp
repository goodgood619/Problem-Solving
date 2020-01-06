#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    Int one;
    Int two;
};
void update(Int index,Int h,Int value, vector<p> &seg) {
    index += h-1;
    seg[index] = {0,value};
    while(index>1) {
        index/= 2;
        Int temp[4] ={seg[index*2].one,seg[index*2].two,seg[index*2+1].one,seg[index*2+1].two};
        sort(temp,temp+4);
        seg[index] = {temp[2],temp[3]};
    }
}
p query(Int nodenum,Int left,Int right, Int nodeleft,Int noderight, vector<p> &seg) {
    if(right < nodeleft || left>noderight) return {0,0};
    else if(left<=nodeleft && noderight<=right) return seg[nodenum];
    Int mid = (nodeleft+noderight)/2;
    p maxleft = query(nodenum*2,left,right,nodeleft,mid,seg);
    p maxright = query(nodenum*2+1,left,right,mid+1,noderight,seg);
    Int temp[4]= {maxleft.one,maxleft.two,maxright.one,maxright.two};
    sort(temp,temp+4);
    return {temp[2],temp[3]};
}
int main() {
    vector<p> seg;
    Int h = 1,n,m;
    scanf("%d",&n);
    while(h<n) h*=2;
    seg.assign(h*2,{0,0});
    for(int i=1;i<=n;i++) {
        Int num;
        scanf("%d",&num);
        update(i,h,num,seg);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        Int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a==1) {
            update(b,h,c,seg);
        } else{
            p ans = query(1,b,c,1,h,seg);
            printf("%d\n",ans.one + ans.two);
        }
    }
    return 0;
}