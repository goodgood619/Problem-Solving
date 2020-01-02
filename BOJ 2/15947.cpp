#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n;
    scanf("%d",&n);
    Int mok = n / 14;
    Int mod = n % 14;
    if(mod == 0 || mod == 2) printf("sukhwan\n");
    else if(mod == 1 || mod == 13) printf("baby\n");
    else if(mod == 3 || mod == 7 || mod == 11) { // tururu
        if(mok >= 3) {
            printf("tu+ru*%d\n",mok + 2);
        }
        else if(mok == 0 ) printf("tururu");
        else if(mok == 1) printf("turururu");
        else if(mok == 2) printf("tururururu");
    }
    else if(mod == 4 || mod == 8 || mod == 12) { // turu
        if(mok >= 4) {
            printf("tu+ru*%d",mok+1);
        }
        else if(mok == 0) printf("turu");
        else if(mok == 1) printf("tururu");
        else if(mok == 2) printf("turururu");
        else if(mok == 3) printf("tururururu");
    }
    else if(mod == 5) printf("very\n");
    else if(mod == 6) printf("cute\n");
    else if(mod == 9) printf("in\n");
    else if(mod == 10) printf("bed\n");
    return 0;
}