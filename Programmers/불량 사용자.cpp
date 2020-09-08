#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
bool check(string& user_id,string& banned_id) {
    if (user_id.size() != banned_id.size()) return false;
    for (int i = 0; i < user_id.size(); ++i) {
        if (user_id[i] == banned_id[i] || banned_id[i] == '*') continue;
        else return false;
    }
    return true;
}
void dfs(vector<string> &user_id,vector<string> &banned_id,int index,int n,int sum,set<int>& s,vector<bool> &visited) {
    if (index == n) {
        s.insert(sum);
        return;
    }
    for (int i = 0; i < user_id.size(); i++) {
        if (!visited[i] && check(user_id[i],banned_id[index])) {
            visited[i] = true;
            dfs(user_id, banned_id, index + 1, n, sum | (1 << i), s, visited);
            visited[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<int> s;
    int n = user_id.size();
    int m = banned_id.size();
    vector<bool> visited;
    visited.assign(user_id.size(),false);
    dfs(user_id, banned_id, 0, m, 0, s,visited);
    answer = s.size();
    return answer;
}