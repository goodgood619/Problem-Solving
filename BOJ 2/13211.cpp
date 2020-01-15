#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n, m;
    scanf("%d", &n);
    vector<string> v;
    for (int i = 0; i < n; i++) {
        char* s = new char[16];
        scanf("%s", s);
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char* s = new char[16];
        scanf("%s", s);
        auto idx = lower_bound(v.begin(), v.end(), s) - v.begin();
        if (idx != v.size() && v[idx] == s) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}