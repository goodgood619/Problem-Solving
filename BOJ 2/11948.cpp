#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    vector<int> a,b;
    for(int i=0;i<4;i++){
        int num;
        scanf("%d",&num);
        a.push_back(num);
    }
    for(int i=0;i<2;i++){
        int num;
        scanf("%d",&num);
        b.push_back(num);
    }
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    int sum=0;
    for(int i=0;i<a.size()-1;i++){
        sum += a[i];
    }
    sum += b[0];
    printf("%d\n",sum);
    return 0;
}