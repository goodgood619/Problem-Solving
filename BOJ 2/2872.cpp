#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef int64_t ll;
int main() {
    int n;
    scanf("%d", &n);
    int* arr = new int[n];
    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (max < arr[i]) max = arr[i];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (max == arr[i]) max--;
    }
    printf("%d\n", max);
    return 0;
}