#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> lines;
    lines.assign(13, vector<int>(0, 0));
    for (int i = 0; i < 12; i++) {
        int start, end;
        scanf("%d%d", &start, &end);
        lines[start].push_back(end);
        lines[end].push_back(start);
    }
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        if (lines[i].size() >= 3) {
            int next1 = lines[i][0];
            int next2 = lines[i][1];
            int next3 = lines[i][2];

            if (lines[next1].size() + lines[next2].size() + lines[next3].size() == 6) {
                ans = i;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
