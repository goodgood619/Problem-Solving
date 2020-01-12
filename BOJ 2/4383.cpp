#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstdint>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> v;
        int check[3000] = { 0, };
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            v.push_back(num);
        }
        if (v.size() == 1) {
            printf("Jolly\n");
        }
        else {
            for (int i = 0; i < v.size() - 1; i++) {
                check[abs(v[i] - v[i + 1])]++;
            }
            bool no = false;
            for (int i = 1; i < n; i++) {
                if (!check[i]) {
                    no = true;
                    break;
                }
            }
            printf("%s\n", no ? "Not jolly":"Jolly");
        }
    }
    return 0;
}