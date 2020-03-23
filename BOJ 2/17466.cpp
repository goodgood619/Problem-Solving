#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int main() {
    ll n, p;
    scanf("%lld%lld", &n, &p);
    ll ans = 1;
    for (ll i = n; i >= 1; i--) {
        ans = ans * i;
        ans %= p;
    }
    printf("%lld\n", ans);
    return 0;
}