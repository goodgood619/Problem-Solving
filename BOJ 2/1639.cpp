#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(int st,int en,string &s,int &ans) {
    int left = 0, right = 0;
    for (int i = st,j=en; i <= (st+en)/2; i++,j--) {
        left += (s[i] - '0'), right += (s[j] - '0');
    }
    if (left == right) ans = max(ans, en - st + 1);
}
int main() {
    char* c = new char[102];
    scanf("%s", c);
    string s = c;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            if ((j - i + 1) % 2) continue;
            go(i, j, s, ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}