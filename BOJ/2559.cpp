#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
void update(int index,int value,vector<int> &seg, int h){
    index += h-1;
    seg[index] = value;
    while(index > 1){
        index /= 2;
        seg[index] = seg[index*2] + seg[index*2+1];
    }
}
int query(int nodenum,int nodeleft,int noderight, int left, int right, vector<int> &seg){
    if(left> noderight || right<nodeleft) return 0;
    else if(left<= nodeleft && noderight <= right) return seg[nodenum];
    int mid = (nodeleft + noderight) / 2;
    return query(nodenum*2,nodeleft,mid,left,right,seg) + query(nodenum*2+1,mid+1,noderight,left,right, seg);
}

int main() {
    int n,k,h = 1;
    scanf("%d%d",&n,&k);
    vector<int> seg;
    while(h<n) h*=2;
    seg.assign(h*2,0);
    for(int i = 1; i<= n;i++){
        int num;
        scanf("%d",&num);
        update(i,num,seg,h);
    }

    int ans = -1e9;
    for(int i = 1 ; i<=n-k+1;i++){
        ans = max(ans, query(1,1,h,i,i+k-1,seg));
    }
    printf("%d\n",ans);
    return 0;
}