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
    
    Int t;
    scanf("%d", &t);
    while (t--) {
        Int n, k,cnt = 0;
        scanf("%d%d", &n, &k);
        for (int i = n; i <= k; i++) {
            string s = to_string(i);
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '0') cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}