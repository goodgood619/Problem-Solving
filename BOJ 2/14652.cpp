#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int ans1 =0, ans2=0;
    for(int i=0;;i++){
        if(k-m*i<m){
            ans1 = i,ans2 = k-m*i;
            break;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}