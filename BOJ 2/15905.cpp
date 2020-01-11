#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
#include <vector>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    int num, penal;
};
bool compare(const p& a, const p& b) {
    if (a.num != b.num) return a.num > b.num;
    if (a.penal != b.penal) return a.penal < b.penal;
}
int main() {
    Int n;
    scanf("%d", &n);
    vector<p> v;
    for (int i = 0; i < n; i++) {
        int num, penal;
        scanf("%d%d", &num, &penal);
        v.push_back({ num,penal });
    }
    sort(v.begin(), v.end(), compare);
    int ans = 0;
    for (int i = 5; i < v.size(); i++) {
        if (v[4].num == v[i].num) ans++;
    }
    printf("%d\n", ans);
    return 0;
}