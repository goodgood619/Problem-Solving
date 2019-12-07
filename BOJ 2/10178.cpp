#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("You get %d piece(s) and your dad gets %d piece(s).\n",a/b,a%b);
    }
    return 0;
}