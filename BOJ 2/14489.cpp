#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a+b >= 2*c ? printf("%d\n",a+b - 2*c) : printf("%d\n",a+b);
    return 0;
}