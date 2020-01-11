#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    Int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) printf("1");
    for (int i = 0; i < n - 1; i++) printf("0");
    return 0;
}