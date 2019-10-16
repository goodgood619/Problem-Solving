#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int t, n, m, c;
int map[10][10];
int d[10][10];
 
//최대값 계산하기
int calc(vector<int> &v, int n, int sum, int val) {
    if (sum > c) return 0;
    if (n == v.size()) return val;
    
    return max(calc(v, n + 1, sum + v[n], val + v[n] * v[n]), calc(v, n + 1, sum, val));
}
 
// 최대값 찾기
int getMaxPrice(int x,int y) {
    vector<int> v;
    for (int i = 0; i < m; i++) {
        v.push_back(map[x][y + i]);
    }
    return calc(v, 0, 0, 0);
}
 
int dfs(int x,int y) {
    int ans = 0;
    //같은라인
    for (int i = y + m; i < n - m + 1; i++) {
        ans = max(ans, d[x][i]);
    }
    //다음라인
    for (int i = x + 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, d[i][j]);
        }
    }
    return ans;
}
 
int main() {
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
                d[i][j] = 0;
            }
        }
 
        //d배열에 그칸부터 m칸까지의 최대값 저장
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - m + 1; j++) {
                d[i][j] = getMaxPrice(i, j);
            }
        }
 
        //i,j를 선택한 상태에서 찾을수 있는 나머지에 대해
        //비교하여 최대값 찾는다.
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - m + 1; j++) {
                res = max(res, dfs(i, j)+d[i][j]);
            }
        }
        printf("#%d %d\n", tc, res);
    }
}