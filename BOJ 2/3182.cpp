#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int go(int start, int*& arr,int n) {
    bool* check = new bool[n + 1];
    for (int i = 1; i <= n; i++) check[i] = false;
    int cnt = 0;
    while (check[start] == false) {
        check[start] = true;
        cnt++;
        start = arr[start];
    }
    delete[] check;
    return cnt;
}
int main() {
    int n,sum = -1,idx=-1;
    scanf("%d", &n);
    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    for (int i = 1; i <= n; i++) {
        int res = go(i, arr,n);
        if (sum < res) {
            sum = res;
            idx = i;
        }
    }
    printf("%d", idx);
    delete[] arr;
    return 0;
}