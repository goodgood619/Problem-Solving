#include <cstdio>
#include <cstring>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int ans,ab,ca,bc;
int main()
{
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int a, b, c;
        ans = 0, ab = 0, bc = 0, ca = 0;
        scanf("%d%d%d", &a, &b, &c);
        scanf("%d%d%d", &ab, &bc, &ca);
        int first = min(a, b), second = min(a, c), third = min(b, c);
        vector<int> v;
        v.push_back(first);
        v.push_back(second);
        v.push_back(third);
        for (int i = 0; i <= first; i++) {//ab
            for (int j = 0; j <= min(a-i,c); j++) { //ac
                ans = max(ans,i* ab + j * ca + min(b - i, c-j) * bc);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}