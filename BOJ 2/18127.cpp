#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", 1LL*(a-2)*b*(b+1)/2+b+1);
    return 0;
}