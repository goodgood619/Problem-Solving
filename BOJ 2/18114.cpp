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
    Int n, c;
    scanf("%d%d", &n, &c);
    vector<Int> v;
    for (int i = 0; i < n; i++) {
        Int num;
        scanf("%d", &num);
        v.push_back(num);
        if (num == c) {
            printf("1");
            return 0;
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        auto idx = lower_bound(v.begin(), v.end(), c - v[i])-v.begin();
        if (idx != i && idx<v.size() && v[idx] == c-v[i]) {
            printf("1");
            return 0;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (c - v[i] - v[j] <= 0) continue;
            auto idx = lower_bound(v.begin(), v.end(), c - v[i] - v[j]) - v.begin();
            if (idx != i && idx != j && idx<v.size() && v[idx] == c-v[i]-v[j]) {
                printf("1");
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}