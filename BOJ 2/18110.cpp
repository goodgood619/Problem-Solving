#include <cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef int64_t ll;
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0) printf("0");
    else {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        double num = n * 0.15;
        if (num - (int)num >= 0.5) {
            num = (int)num + 1;
        }
        int num2 = (int)num, sum = 0, cnt = 0;
        for (int i = num2; i < v.size() - num2; i++) {
            sum += v[i];
            cnt++;
        }
        double check = sum / (cnt * 1.0);
        int ans = 0;

        if (check - (int)check >= 0.5) {
            ans = (int)check + 1;
        }
        else ans = (int)check;
        printf("%d", ans);
    }
    return 0;
}