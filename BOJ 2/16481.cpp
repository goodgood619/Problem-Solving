#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    // 1/R = 1/r1 + 1/r2 + 1/r3
    double r1,r2,r3;
    scanf("%lf%lf%lf",&r1,&r2,&r3);
    printf("%.6lf\n",1/(1/r1 + 1/r2 + 1/r3));
    return 0;
}