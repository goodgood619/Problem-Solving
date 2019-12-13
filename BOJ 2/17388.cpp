#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a+b+c >= 100) printf("OK");
    else {
        if(a < b && a < c) printf("Soongsil");
        else if(b<a && b<c) printf("Korea");
        else if(c<a && c<b) printf("Hanyang");
    }
    return 0;
}