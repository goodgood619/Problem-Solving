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
    Int t;
    scanf("%d", &t);
    int cnt = 1;
    while (t--) {
        Int n;
        scanf("%d", &n);
        vector<ll> v;
        for (int i = 0; i < 2 * n; i++) {
            ll num;
            scanf("%lld", &num);
            v.push_back(num);
        }
        vector<ll> ans;
        Int check[201] = { 0, };
        for (int i = 0; i < v.size(); i++) {
            if (v[i] % 4 || check[i]) continue;
            for (int j = 0; j < i; j++) {
                if (v[j] == v[i] * 3 / 4 && check[j] ==0 ) {
                    ans.push_back(v[j]);
                    check[j] = 1;
                    check[i] = 1;
                    break;
                }
            }
        }
        printf("Case #%d: ",cnt++);
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}