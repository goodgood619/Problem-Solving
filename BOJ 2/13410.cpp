#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v;
    for (int i = 1; i <= k; i++) {
        int num = n * i;
        string s = to_string(num);
        reverse(s.begin(), s.end());
        v.push_back(stoi(s));
    }
    sort(v.begin(), v.end(), greater<Int>());
    printf("%d\n", v[0]);
    return 0;
}