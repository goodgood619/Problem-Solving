#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int score[33];
bool change_dir[33];
int v[33][2];
int horse[4];
bool check[33];
void go(int here,int total,int &ans,vector<int> &play) {
    if (here == 10) {
        ans = max(ans, total);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int temp = play[here];
        int position = horse[i];
        int back = position;
        //방향전환
        if (change_dir[position]) {
            temp--;
            position = v[position][1];
        }
        while (temp--) {
            position = v[position][0];
        }
        if (position != 21 && check[position]) continue;
        horse[i] = position;
        check[position] = true;
        check[back] = false;
        go(here + 1, total + score[position], ans, play);
        horse[i] = back;
        check[back] = true;
        check[position] = false;

    }
}
int main() {
    // 각 노드의 그 다음노드 세팅, 즉 이것이 화살표 세팅이라고 보면 된다.
    for (int i = 0; i <= 24; i++) {
        v[i][0] = i + 1;
    }

    v[21][0] = 21;

    v[25][0] = 31;
    v[26][0] = 25;
    v[27][0] = 26;
    v[28][0] = 27;
    v[29][0] = 30;
    v[30][0] = 25;
    v[31][0] = 32;
    v[32][0] = 20;

    v[5][1] = 22;
    v[10][1] = 29;
    v[15][1] = 28;

    change_dir[5] = change_dir[10] = change_dir[15] = true;            // 이 곳에서 시작하면, 방향을 바꿔줘야하기 때문에 설정해준다.

    // 점수세팅
    for (int i = 1; i <= 20; i++) score[i] = 2 * i;
    for (int i = 22; i <= 24; i++) score[i] = 13 + 3 * (i - 22);
    score[25] = 25;
    for (int i = 26; i <= 28; i++) score[i] = i;
    score[31] = 30;
    score[32] = 35;
    score[29] = 22;
    score[30] = 24;

    vector<int> play;
    for (int i = 0; i < 10; i++) {
        int num;
        scanf("%d", &num);
        play.push_back(num);
    }
    int ans = 0;
    go(0, 0,ans,play);
    printf("%d\n", ans);
	return 0;
}