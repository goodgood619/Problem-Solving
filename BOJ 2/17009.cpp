#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int a=0,b=0,one,two,three;
    scanf("%d",&one);
    a += (3*one);
    scanf("%d",&two);
    a += (2*two);
    scanf("%d",&three);
    a += three;
    scanf("%d",&one);
    b += (3*one);
    scanf("%d",&two);
    b += (2*two);
    scanf("%d",&three);
    b += three;
    if(a>b) printf("A");
    else if(a<b) printf("B");
    else printf("T");
    return 0;
}