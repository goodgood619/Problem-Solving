#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    // 4k^2 =  (d2-d1)^2 + 4*h^2;
    double k,d1,d2;
    scanf("%lf%lf%lf",&k,&d1,&d2);
    printf("%.6lf\n",(4*k*k-(d2-d1)*(d2-d1))/4);
    return 0;
}