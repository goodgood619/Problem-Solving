#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cstring>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(int idx1,int idx2,vector<int> &v) {
    int temp = v[idx1];
    v[idx1] = v[idx2];
    v[idx2] = temp;
}
int main() {
    vector<int> v;
    v.assign(3, 0);
    v[0] = 1;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') go(0, 1, v);
        if (s[i] == 'B') go(1, 2, v);
        if (s[i] == 'C') go(0, 2, v);
    }
    for (int i = 0; i < 3; i++) {
        if (v[i] == 1) printf("%d\n", i + 1);
    }
    return 0;
}