#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef int64_t ll;
int gox[4] = { 0,0,-1,1 };
int goy[4] = { 1,-1,0,0 };
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    vector<int> v;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        sum += v[i];
    }
    int totalSum = sum;
    sum /= 3;
    if (totalSum % 3 != 0) printf("NO");
    else {
        for (auto value : v) {
            sum -= (value / 2);
        }
        printf("%s\n", sum > 0 ? "NO" : "YES");
    }
    v.clear();
    return 0;
}