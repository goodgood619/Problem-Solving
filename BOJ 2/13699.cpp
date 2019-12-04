#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d",&n);
    ll *arr = new ll[n+1];
    for(int i=0;i<=n;i++) arr[i] = 0;
    arr[0] = 1,arr[1] = 1;
    for(int i=2;i<=n;i++){
        ll temp = 0;
        for(int j = 0;j<i;j++){
            temp += (arr[j]*arr[i-1-j]);
        }
        arr[i] = temp;
    }
    printf("%lld\n",arr[n]);
    delete[] arr;
    return 0;
}
