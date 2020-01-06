#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
Int stroke[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int main() {
    string a,b;
    cin >> a >> b;
    vector<int> temp;
    for(int i=0;i<a.size();i++) {
        temp.push_back(stroke[a[i]-'A']);
        temp.push_back(stroke[b[i]-'A']);
    }
    vector<int> couple;
    while(true) {
        for(int i=0;i<temp.size()-1;i++) {
            couple.push_back((temp[i]+temp[i+1])%10);
        }
        if(couple.size() == 2) break;
        temp = couple;
        couple.clear();
    }
    printf("%d%d\n",couple[0],couple[1]);
    return 0;
}