#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int max = -1e9,min = 1e9;
    vector<int> arr;
    arr.assign(10, 0);
    for (int i = 0; i < 10; i++) {
        int num;
        scanf(" %d", &num);
        arr[i] = num;
        if (max < num) max = num;
        if (min > num) min = num;
    }
    v.assign(max+1, 0);
    for (auto value : arr) {
        v[value]++;
    }
    printf("counting sort «— ¿Ã»ƒ \n");
    for (int i = 0; i < v.size(); i++) {
        int cnt = v[i];
        while (cnt--) {
            printf("%d ",i);
        }
    }
    return 0;
}