#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n,s1 = 100, s2 = 100;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b){
            s2 -= a;
        }
        else if(a<b){
            s1 -= b;
        }
    }
    printf("%d\n%d\n",s1,s2);
    return 0;
}