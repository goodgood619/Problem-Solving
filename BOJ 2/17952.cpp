#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
struct p {
    int score, minute;
};
int main() {
    int n,sum=0;
    stack<p> st;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int what;
        scanf("%d", &what);
        if (what == 0) {
            if (st.empty()) continue;
            p res = st.top();
            res.minute--;
            if (res.minute == 0) {
                st.pop();
                sum += res.score;
            }
            else {
                st.pop();
                st.push({ res.score, res.minute });
            }
        }
        else {
            int score, minute;
            scanf("%d%d", &score, &minute);
            minute--;
            if (minute == 0) {
                sum += score;
            }
            else {
                st.push({ score,minute });
            }
        }
    }
    printf("%d", sum);
    return 0;
}