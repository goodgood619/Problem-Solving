#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int main() {
    int n,Max=1;
    scanf("%d", &n);
    int* arr = new int[n + 1];
    int* dp = new int[n + 1];
    for (int i = 1; i <= n; i++) dp[i] = 1;
    for (int i = 1; i <= n; i++) scanf(" %d", &arr[i]);
    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                Max = max(Max, dp[i]);
            }
        }
    }
    printf("%d\n", n - Max);
    delete[] arr, dp;
    return 0;
}