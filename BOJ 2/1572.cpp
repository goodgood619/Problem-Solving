#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void update(vector<int> &seg,int value,int nodeleft,int noderight,int nodenum,int temp) {
    if (nodeleft > temp || temp > noderight) return;
    if (nodeleft == noderight) {
        seg[nodenum] += value;
        return;
    }
     int mid = (nodeleft + noderight) / 2;
    update(seg, value,nodeleft, mid,nodenum*2,temp);
    update(seg,value, mid + 1, noderight,nodenum*2+1,temp);
    seg[nodenum] = seg[nodenum * 2] + seg[nodenum * 2 + 1];
}
int query(int nodenum,int nodeleft,int noderight,vector<int> &seg,int value) {
    if (nodeleft == noderight) {
        return nodeleft;
    }
    int mid = (nodeleft + noderight) / 2;
    if (value > seg[nodenum*2]) return query(nodenum * 2 + 1, mid + 1, noderight, seg, value - seg[nodenum*2]);
    else return query(nodenum * 2, nodeleft, mid, seg, value);
}
int main() {
    Int n, k;
    scanf("%d%d", &n, &k);
    Int h = 65536;
    vector<int> seg;
    Int* temp = new Int[n + 1];
    for (int i = 0; i <= n; i++) temp[i] = 0;
    seg.resize(h * 2, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) scanf(" %d", &temp[i]);
    for (int i = 1; i < k; i++) update(seg,1, 0, h,1, temp[i]);
    for (int i = k; i <= n; i++) {
        update(seg, 1, 0, h, 1, temp[i]);
        ans += (ll)query(1, 0, h, seg, (k + 1) / 2);
        update(seg, -1, 0, h, 1, temp[i - k + 1]);
    }
    printf("%lld\n", ans);
    delete[] temp;
    return 0;
}