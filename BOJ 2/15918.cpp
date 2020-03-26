#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef int64_t ll;
int ans = 0;
void go(int here, bool*& visited, int*& num, int n) {
    if (here == 2 * n + 1) {
        ans++;
        return;
    }
    if (num[here] > 0) go(here + 1, visited, num, n);
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && here+i+1<=2*n && num[here] == 0 && num[here + i + 1] == 0) {
            num[here] = i;
            num[here + i + 1] = i;
            visited[i] = true;
            go(here + 1, visited, num, n);
            num[here] = num[here + i + 1] = 0;
            visited[i] = false;
        }
    }
}
int main() {
    int n,x,y;
    scanf("%d%d%d", &n, &x, &y);
    bool* visited = new bool[n + 1];
    int* num = new int[2 * n + 1];
    for (int i = 1; i <= n; i++) visited[i] = false;
    for (int i = 1; i <= 2 * n; i++) num[i] = 0;
    visited[y - x - 1] = true;
    num[x] = y - x - 1;
    num[y] = y - x - 1;
    go(1,visited,num,n);
    printf("%d\n", ans);
    delete[] visited, num;
    return 0;
}