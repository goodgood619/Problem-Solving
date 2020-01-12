#include <cstdio>
#include <algorithm>
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
    int cnt = 2;
    vector<int> v;
    for (int i = n; i >= 1; i--) {
        int temp = 2, first = n, second = i;
        vector<int> tv;
        tv.push_back(first), tv.push_back(second);
        while (true) {
            int third = first - second;
            if (third < 0) break;
            temp++;
            first = second;
            second = third;
            tv.push_back(third);
        }
        if (cnt < temp) {
            cnt = temp;
            v = tv;
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }

    return 0;
}