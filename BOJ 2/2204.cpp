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
struct p {
    string origin;
    string temp;
};
bool compare(const p &a,const p &b) {
    if (a.temp != b.temp) return a.temp < b.temp;
}
int main() {
    Int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        vector<p> v;
        for (int i = 0; i < n; i++) {
            string origin;
            cin >> origin;
            string t = origin;
            for (int j = 0; j < t.size(); j++) {
                if (t[j] >= 'A' && t[j] <= 'Z') t[j] += 32;
            }
            v.push_back({ origin,t });
        }
        sort(v.begin(), v.end(), compare);
        printf("%s\n", v[0].origin.c_str());
    }
    return 0;
}