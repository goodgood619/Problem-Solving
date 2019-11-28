#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf(" %d",&n);
        int num;
        scanf(" %d",&num);
        for(int i=0;i<num;i++){
            int a,b;
            scanf("%d%d",&a,&b);
             n += (a*b);
        }
        printf("%d\n",n);
    }
    return 0;
}