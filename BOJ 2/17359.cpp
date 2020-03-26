#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef int64_t ll;
int ans = 1e9;
struct p {
    string s;
    int sum;
};
int cal(string s) {
    int sum = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) sum++;
    }
    return sum;
}
void go(int cnt, int depth, vector<p>& v, bool*& visited, vector<int>& temp) {
    if (cnt == depth) {
        int total = 0;
        for (int i = 0; i < temp.size() - 1; i++) {
            int l1 = v[temp[i]].s.size() - 1;
            if (v[temp[i]].s[l1] != v[temp[i + 1]].s[0]) total++;
            total += v[temp[i]].sum;
        }
        total += v[temp[temp.size() - 1]].sum;
        ans = min(ans, total);
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp.push_back(i);
            go(cnt + 1, depth, v, visited, temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
}
int main() {
    int n;
    scanf(" %d", &n);
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++) visited[i] = false;
    vector<p> v;
    vector<int> temp;
    for (int i = 1; i <= n; i++) {
        char s[102] = { '\0', };
        scanf("%s", s);
        string c = s;
        v.push_back({ c, cal(c) });
    }
    go(0, n, v, visited, temp);
    printf("%d\n", ans);
    delete[] visited;
    return 0;
}