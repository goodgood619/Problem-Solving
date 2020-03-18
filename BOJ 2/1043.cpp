#include <cstdio>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;
typedef int64_t ll;
int main() {
    int n, m,know;
    scanf("%d%d", &n, &m);
    bool* visited = new bool[n+1];
    memset(visited, false, sizeof(visited));
    scanf("%d", &know);
    for (int i = 0; i < know; i++) {
        int num;
        scanf("%d", &num);
        visited[num] = true;
    }

    if (know == 0) {
        printf("%d", m);
        return 0;
    }
    vector<vector<int>> v;
    for (int i = 0; i < m; i++) {
        int cnt;
        scanf("%d", &cnt);
        vector<int> temp;
        for (int j = 0; j < cnt; j++) {
            int num;
            scanf("%d", &num);
            temp.push_back(num);
        }
        v.push_back(temp);
    }

    for (int k = 0; k < m; k++) {
        for (auto e : v) {
            bool ok = false;
            for (auto e2 : e) {
                if (visited[e2]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                for (auto e2 : e) {
                    visited[e2] = true;
                }
            }
        }
    }

    int cnt = 0;
    for (auto e : v) {
        bool ok = false;
        for (auto e2 : e) {
            if (visited[e2]) {
                ok = true;
                break;
            }
        }
        if (!ok) cnt++;
    }
    printf("%d\n", cnt);
    delete[] visited;
    return 0;
}