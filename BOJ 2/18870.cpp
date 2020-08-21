#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef int64_t ll;
int gox[4] = { 0,0,-1,1 };
int goy[4] = { 1,-1,0,0 };
int main()
{
    
    int n;
    scanf(" %d", &n);
    vector<int> v;
    v.assign(n, 0);
    set<int> set;
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        set.insert(v[i]);
    }
    vector<int> lowerList;
    lowerList.assign(set.size(), 0);
    int idx = 0;
    for (auto value : set) {
        lowerList[idx++] = value;
    }
    sort(lowerList.begin(), lowerList.end());
    for (auto value : v) {
        auto ans = lower_bound(lowerList.begin(),lowerList.end(),value)-lowerList.begin();
        printf("%d ", ans);
    }
    return 0;
}