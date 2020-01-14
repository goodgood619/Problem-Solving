#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n;
    vector<ll> plus,minus;
    int one = 0, zero = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll num;
        scanf("%lld", &num);
        if (num == 0) zero++;
        else if (num == 1) one++;
        else if (num > 0) plus.push_back(num);
        else if (num < 0) minus.push_back(num);
    }
    sort(plus.begin(), plus.end(), greater<ll>());
    sort(minus.begin(), minus.end());
    ll ans = 0;
    ans += one;
    for (int i = 0; i < (int)plus.size() - 1; i+=2) {
        ans += plus[i] * plus[i + 1];
    }
    if (plus.size() % 2) ans += plus[plus.size() - 1];
    for (int i = 0; i < (int)minus.size()-1; i+=2) {
        ans += minus[i] * minus[i + 1];
    }
    if (minus.size() % 2 && zero ==0) ans += minus[minus.size() - 1];
    printf("%lld\n", ans);
    return 0;
}