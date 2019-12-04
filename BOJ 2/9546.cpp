#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    int arr[31]={0,1,};
    for(int i=2;i<=30;i++) arr[i] = 2* arr[i-1] + 1;
    while(t--){
        int k;
        scanf("%d",&k);
        printf("%d\n",arr[k]);
    }
    return 0;
}
