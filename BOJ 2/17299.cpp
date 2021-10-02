#include <cstdio>
#include <vector>
#include <map>
#include <stack>
using namespace std;

int main() {
    stack<pair<int,int>> st;
    int n;
    scanf("%d", &n);
    vector<int> a,ans,number;

    a.assign(n+1,0);
    ans.assign(n+1,0);
    number.assign(1000001,0);
    for (int i = 1; i <= n; i++) scanf(" %d", &a[i]);

    for(int i=1;i<=n;i++) {
        number[a[i]]++;
    }

    for (int i = n; i >= 1; i--) {
        while (!st.empty() && st.top().second <= number[a[i]]) st.pop();
        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top().first;
        st.push({a[i],number[a[i]]});
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}