#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    int* notprime = new int[1000001];
    for (int i = 0; i <= 1000000; i++) notprime[i] = 0;
    for (int i = 2; i <= sqrt(1000000); i++) {
        if (notprime[i]) continue;
        for (int j = i * i; j <= 1000000; j += i) {
            notprime[j] = 1;
        }
    }
    vector<int> v;
    for (int i = 2; i <= 1000000; i++) {
        if (!notprime[i]) v.push_back(i);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            auto idx = lower_bound(v.begin(), v.end(), n - v[i]) - v.begin();
            if (idx != v.size() && v[idx] + v[i] == n && v[idx] != v[i]) cnt++;
            else if (idx != v.size() && v[idx] + v[i] == n && v[idx] == v[i]) cnt += 2;
        }
        cnt /= 2;
        printf("%d\n", cnt);
    }
    return 0;
}