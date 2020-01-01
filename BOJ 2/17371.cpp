#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p{
    int x;
    int y;
};
int dist(int x1,int y1,int x2,int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main() {
    Int n;
    scanf("%d",&n);
    vector<p> v;
    for(int i=0;i<n;i++){
        Int x,y;
        scanf("%d%d",&x,&y);
        v.push_back({x,y});
    }
    int ans = 1e9,idx = -1;
    for(int i=0;i<n;i++) {
        int temp = 0;
        for(int j=0;j<n;j++) {
            temp = max(temp,dist(v[i].x,v[i].y,v[j].x,v[j].y));
        }
        if(ans > temp) {
            ans = temp;
            idx = i;
        }
    }
    printf("%d %d\n",v[idx].x,v[idx].y);
    return 0;
}