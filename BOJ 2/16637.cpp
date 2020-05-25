#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef int64_t ll;
ll ans = -1e18;
ll calc(char c, ll n1, ll n2) {
    if (c == '*') return n1 * n2;
    else if (c == '+') return n1 + n2;
    else return n1 - n2;
}
void dfs(ll result, int curopidx, vector<char>& op, vector<int>& nums) {
    if (curopidx >= op.size()) {
        ans = max(ans, result);
        return;
    }
    ll res1 = calc(op[curopidx], result, nums[curopidx + 1]);
    dfs(res1, curopidx + 1,op,nums);
    if (curopidx + 1 < op.size()) {
        ll res2 = calc(op[curopidx + 1], nums[curopidx + 1], nums[curopidx + 2]);
        dfs(calc(op[curopidx],result,res2), curopidx + 2, op, nums);
    }
}
int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<char> op;
    vector<int> nums;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') op.push_back(s[i]);
        else nums.push_back(s[i] - '0');
    }
    dfs(nums[0], 0, op, nums);
    printf("%d\n", ans);
    return 0;
}