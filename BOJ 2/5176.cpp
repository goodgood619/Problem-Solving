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
    int t;
    scanf("%d", &t);
    while (t--) {
        int p, m;
        scanf("%d%d", &p, &m);
        int cnt = 0;
        int* check = new int[p + 1];
        for (int i = 0; i <= p; i++) check[i] = 0;
        for (int i = 1; i <= p; i++) {
            int num;
            scanf("%d", &num);
            if (check[num] == 0) check[num] = 1;
            else cnt++;
        }
        printf("%d\n", cnt);
        delete[] check;
    }
    return 0;
}