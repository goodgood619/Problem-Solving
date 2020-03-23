#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int ans;
void go(int cnt, int depth, int k, vector<int>& v, vector<int>& temp, bool*& visited) {
    if (cnt == depth) {
        int start = 500;
        for (int i = 0; i < temp.size(); i++) {
            int diff = temp[i] - k;
            start += diff;
            if (start < 500) return;
        }
        ans++;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(v[i]);
            go(cnt + 1, depth, k, v, temp, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v,temp;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    bool* visited = new bool[v.size()];
    for (int i = 0; i < v.size(); i++) visited[i] = false;
    go(0, n, k, v, temp, visited);
    printf("%d\n", ans);
    return 0;
}