#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    int cnt = 1;
    while(true) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        if(a == 0 && b ==0 && c == 0) break;
       if(a == -1) {
            if(b>=c) {
                printf("Triangle #%d\nImpossible.\n",cnt++);
            }
            else {
                double ans = sqrt(c*c - b*b);
                printf("Triangle #%d\na = %.3lf\n",cnt++,ans);
            }
       }
       else if(b == -1) {
            if(a>=c) {
                printf("Triangle #%d\nImpossible.\n",cnt++);
            }
            else {
                double ans = sqrt(c*c - a*a);
                printf("Triangle #%d\nb = %.3lf\n",cnt++,ans);
            }
       }
       else {
           double ans = sqrt(b*b + a*a);
           printf("Triangle #%d\nc = %.3lf\n",cnt++,ans);
       }
        printf("\n");
    }
    return 0;
}