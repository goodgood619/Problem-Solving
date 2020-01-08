#include <cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    // -x-y = 2*a, x*y = b
    for (int i = -2000; i <= 2000; i++) {
        for (int j = -2000; j <= 2000; j++) {
            if (2 * a == -1 * i + -1 * j && i * j == b) {
                if (i != j) {
                    printf("%d %d\n", i < j ? i : j, i < j ? j : i);
                }
                else printf("%d\n", i);
                return 0;
            }
        }
    }
    return 0;
}