#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
ll go(int l,int r,ll* &sum, ll* &arr) {
    if(l == r) return arr[l] *arr[r];
    int mid = (l+r) / 2;
    ll ret = max(go(l,mid,sum,arr),go(mid+1,r,sum,arr));
    Int left = mid, right = mid+1;
    ll Min = min(arr[left],arr[right]);
    ret = max(ret,Min*(arr[left]+arr[right]));

    while(l < left || right < r) {
        if(l == left || right < r && arr[left-1]<arr[right+1]) {
            right++;
            Min = min(Min,arr[right]);
        }
        else {
            left--;
            Min = min(Min,arr[left]);
        }
        if(left>=1) {
            ret = max(ret,(sum[right]-sum[left-1])*Min);
        }
        else {
            ret = max(ret, sum[right]*Min);
        }
    }
    return ret;
}
int main() {
    Int n;
    scanf("%d",&n);
    ll *sum = new ll[n];
    ll *arr = new ll[n];
    for(int i=0;i<n;i++) {
        sum[i] = 0,arr[i] = 0;
    }
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
    sum[0] = arr[0];
    for(int i=1;i<n;i++) sum[i] += (sum[i-1] + arr[i]);
    printf("%lld\n",go(0,n-1,sum,arr));
    delete[] sum,arr;
    return 0;
}