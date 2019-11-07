#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
void update(vector<int> &seg,int idx,int value,int h){
    idx += h-1;
    seg[idx] = value;
    while(idx>1){
        idx/=2;
        seg[idx] = min(seg[idx*2],seg[idx*2+1]);
    }
}
int query(int nodenum,int left,int right, int nodeleft,int noderight, vector<int> &seg){
    if(right<nodeleft || noderight<left) return 1e9;
    else if(left<=nodeleft &&noderight <= right) return seg[nodenum];
    int mid = (nodeleft+noderight)/2;
    return min(query(nodenum*2,left,right,nodeleft,mid,seg),query(nodenum*2+1,left,right,mid+1,noderight,seg));
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> seg;
    int h =1 ;
    while(h<n) h*=2;
    seg.assign(h*2,1e9);
    for(int i = 1;i<=n;i++){
        int num;
        scanf("%d",&num);
        update(seg,i,num,h);
    }
    int k;
    scanf("%d",&k);
    for(int i =0 ; i<k;i++){
        int what;
        scanf("%d",&what);
        if(what == 1){
            int idx,value;
            scanf("%d%d",&idx,&value);
            update(seg,idx,value,h);
        }
        else {
            int left,right;
            scanf("%d%d",&left,&right);
            printf("%d\n",query(1,left,right,1,h,seg));
        }
    }
    return 0;
}