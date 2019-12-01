#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        double d;
        scanf(" %lf",&d);
        double t = d * 0.2;
        printf("$%.2lf\n",d-t);
    }
    return 0;
}