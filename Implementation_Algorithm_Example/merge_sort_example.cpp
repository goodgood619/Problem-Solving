#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef int64_t ll;
int gox[4] = { 0,0,-1,1 };
int goy[4] = { 1,-1,0,0 };
vector<int> temp;
void merge(vector<int> &v, int left,int mid,int right) {
    int lidx = left, ridx = mid + 1;
    int idx = left;
    while (lidx<=mid && ridx<=right) {
        if (v[lidx] <= v[ridx]) temp[idx++] = v[lidx++];
        else temp[idx++] = v[ridx++];
    }
    while (lidx <= mid) temp[idx++] = v[lidx++];
    while (ridx <= right) temp[idx++] = v[ridx++];

    for (int i = left; i <= right; i++) v[i] = temp[i];
}
void mergesort(vector<int>& v, int left, int right) {
    if (left >= right) return;
    int mid = (left+right)/2;
    if (left < right) {
        mergesort(v, left, mid);
        mergesort(v, mid + 1, right);
        merge(v,left, mid, right);
    }
}
int main()
{
    
    int n;
    scanf(" %d", &n);
    vector<int> v;
    v.assign(n, 0);
    temp.assign(n, 0);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    mergesort(v, 0, v.size() - 1);
    for (auto value : v) {
        printf("%d\n", value);
    }
    return 0;
}