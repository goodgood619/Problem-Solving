#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    double a,b,c,al,bl,cl;
    scanf(" %lf%lf%lf%lf%lf%lf",&a,&b,&c,&al,&bl,&cl);
    double ahr = min({a/al,b/bl,c/cl});
    a -= ahr*al;
    b -= ahr*bl;
    c-= ahr*cl;
    printf("%.4lf %.4lf %.4lf",a,b,c);
    return 0;
}
