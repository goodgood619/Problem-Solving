#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n,hak = 0;
    scanf("%d",&n);
    double total = 0;
    for(int i=0;i<n;i++) {
        string a,c;
        Int b;
        cin >> a >> b >> c;
        if(c == "A+") total += 4.3 * b;
        if(c== "A0") total += 4.0 * b;
        if(c== "A-") total += 3.7*b;
        if(c== "B+") total += 3.3*b;
        if(c== "B0") total += 3.0*b;
        if(c=="B-") total += 2.7*b;
        if(c== "C+") total +=2.3*b;
        if(c== "C0") total +=2.0*b;
        if(c=="C-") total += 1.7*b;
        if(c=="D+") total +=1.3*b;
        if(c=="D0") total +=1.0*b;
        if(c=="D-") total += 0.7*b;
        hak += b;
    }
    total /= hak;
    printf("%.2lf\n",total+ 0.000000000001);

    return 0;
}