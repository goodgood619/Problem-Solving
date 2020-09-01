#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int calculate(int value) {
    int cnt = 0;
    while (value > 0) {
        value /= 10;
        cnt++;
    }
    return cnt;
}
void radix_sort(vector<int> &v,int digit) {
    queue<int> q[10];
    vector<int> temp = v;
    for (int i = 0; i < temp.size(); i++) {
        int originValue = temp[i];
        for (int j = 0; j < digit; j++) {
            temp[i] /= 10;
        }
        q[temp[i]%10].push(originValue);
    }
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        while (!q[i].empty()) {
            v[idx++] = q[i].front();
            q[i].pop();
        }
    }

}
void print(vector<int>& v) {
    for (auto value : v) {
        printf("%d ", value);
    }
    printf("\n");
}
int main()
{
    queue<int> q[10];
    vector<int> v;
    v.assign(8, 0);
    printf("기수 정렬 이전 : \n");
    v[0] = 100, v[1] = 27,v[2] = 64,v[3] = 25,v[4] = 50,v[5] = 17,v[6] = 39,v[7] = -1000;
    print(v);
    int max = 0;
    for (auto value : v) {
        int maxvalue = calculate(value);
        if (max < maxvalue) max = maxvalue;
    }
    for (int i = 0; i < max; i++) {
        radix_sort(v,i);
    }
    printf("기수 정렬을 한 후 : \n");
    print(v);
    return 0;
}