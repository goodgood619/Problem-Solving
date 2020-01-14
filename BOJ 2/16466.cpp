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
    scanf("%d", &n);
    vector<Int> v;
    for (int i = 0; i < n; i++) {
        Int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    if (v[0] != 1)  printf("1\n");
    else {
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i + 1] - v[i] > 1) {
                printf("%d\n", v[i] + 1);
                return 0;
            }
        }
        printf("%lld\n", (ll)v.back() + 1);
    }
    return 0;
}