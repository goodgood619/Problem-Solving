#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
#include <vector>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    int index,num,hour,minute;
};
bool compare(const p &a,const p &b) {
    if (a.hour != b.hour) return a.hour < b.hour;
    if (a.minute != b.minute) return a.minute < b.minute;
    if (a.index != b.index) return a.index < b.index;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        Int k,n,ok=0;
        scanf("%d", &k);
        vector<int> student;
        vector<p> v;
        for (int i = 0; i < k; i++) {
            int num;
            scanf("%d", &num);
            student.push_back(num);
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            Int num, hour, minute;
            scanf("%d%d%d", &num, &hour, &minute);
            if (hour == -1 && minute == -1) continue;
            if (hour * 60 + minute <= 360) {
                bool temp = false;
                int idx = -1;
                for (int j = 0; j < student.size(); j++) {
                    if (student[j] == num) {
                        temp = true;
                        idx = j;
                    }
                }
                if (temp) {
                    ok++;
                    v.push_back({idx,num,hour,minute });
                }
            }
        }
        sort(v.begin(), v.end(), compare);
        printf("%d %d\n", v[0].num, ok);
    }
    return 0;
}