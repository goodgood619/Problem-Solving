#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        double A = 350.34, B = 230.90,  C= 190.55, D = 125.30, E = 180.90;
        printf("$%.2lf\n",A*a + B*b + C*c + D*d + E*e);
    }
    return 0;
}