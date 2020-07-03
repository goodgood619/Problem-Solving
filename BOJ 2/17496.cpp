#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef int64_t ll;
int gox[4] = { 0,0,-1,1 };
int goy[4] = { 1,-1,0,0 };
int main()
{
    int n, t, c, p;
    scanf("%d%d%d%d", &n, &t, &c, &p);
    n--;
    printf("%d\n", (n / t) * c * p);
    return 0;
}