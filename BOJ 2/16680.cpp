#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int go(ll n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        ll n;
        scanf("%lld", &n);
        while (n != 1e18) {
            int res = go(n);
            if (res % 2 == 1) {
                printf("%lld\n", n);
                break;
            }
            n += n;
        }
    }
    return 0;
}