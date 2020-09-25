#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int gox[4] = {-1,1,0,0};
int goy[4] = {0,0,-1,1};
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, string> key;
    for (int i = 0; i < n; i++) {
        char s[12] = { '\0', };
        int battle;
        scanf("%s%d", s, &battle);
        if (key.count(battle) == 0) {
            key[battle] = s;
        }
    }
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        auto it = key.lower_bound(value);
        printf("%s\n", it->second.c_str());
    }
    return 0;
}