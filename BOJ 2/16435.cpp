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
    int n, l;
    scanf("%d%d", &n, &l);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int cur = l;
    for (int i = 0; i < v.size(); i++) {
        if (cur >= v[i]) cur++;
    }
    printf("%d\n", cur);
    return 0;
}