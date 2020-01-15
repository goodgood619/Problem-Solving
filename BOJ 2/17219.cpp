#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    string a;
    string b;
};
int main() {
    Int n, m;
    scanf("%d%d", &n, &m);
    map<string, string> k;
    for (int i = 0; i < n; i++) {
        char* a = new char[21];
        char* b = new char[21];
        scanf("%s %s", a, b);
        k[a] = b;
    }
    for (int i = 0; i < m; i++) {
        char* f = new char[21];
        scanf("%s", f);
        printf("%s\n", k[f].c_str());
   }
   
    return 0;
}