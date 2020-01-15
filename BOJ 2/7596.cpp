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
    int t = 1;
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            char* s = new char[251];
            scanf(" %[^\n]s", s);
            string temp = s;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        printf("%d\n", t++);
        for (int i = 0; i < n; i++) {
            printf("%s\n", v[i].c_str());
        }
        v.clear();
    }
    return 0;
}