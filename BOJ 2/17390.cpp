#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void update(int index,ll value,vector<ll> &seg,int h){
    index += h-1;
    seg[index] = value;
    while(index>1) {
        index /= 2;
        seg[index] = seg[index*2] +seg[index*2+1];
    }
}
ll query(int nodenum,int nodeleft,int noderight,int left,int right,vector<ll> &seg){
    if(right <nodeleft || noderight < left) return 0;
    else if(left <= nodeleft && noderight <= right) return seg[nodenum];
    int mid = (nodeleft + noderight) / 2;
    return query(nodenum*2,nodeleft,mid,left,right,seg) + query(nodenum*2+1,mid+1,noderight,left,right,seg);
}
int main() {
    vector <ll> seg;
    int n,q;
    scanf("%d%d",&n,&q);
    int h = 1;
    while(h < n) h *= 2;
    seg.assign(h*2,0);
    vector <ll> v;
    for(int i=1 ;i<=n ;i++){
        ll num;
        scanf("%lld",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i =0 ;i<v.size();i++){
        update(i+1,v[i],seg,h);
    }

    for(int i = 0 ; i < q; i++) {
        int left,right;
        scanf(" %d%d",&left,&right);
        printf("%lld\n",query(1,1,h,left,right,seg));
    }
    return 0;
}