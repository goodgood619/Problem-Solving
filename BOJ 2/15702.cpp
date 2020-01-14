#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
struct p {
    Int num,score;
};
bool compare(const p &a,const p &b) {
    if (a.score != b.score) return a.score > b.score;
    if (a.num != b.num) return a.num < b.num;
}
int main() {
    Int n, m;
    scanf("%d%d", &n, &m);
    vector<p> v;
    vector<Int> score;
    for (int i = 0; i < n; i++) {
        Int num;
        scanf("%d", &num);
        score.push_back(num);
    }
    for (int i = 0; i < m; i++) {
        Int num;
        scanf("%d", &num);
        Int sscore = 0;
        for (int j = 0; j < n; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'O') sscore += score[j];
        }
        v.push_back({ num,sscore });
    }
    sort(v.begin(), v.end(), compare);
    printf("%d %d\n", v[0].num, v[0].score);
    return 0;
}