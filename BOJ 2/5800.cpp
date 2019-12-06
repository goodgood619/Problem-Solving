#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    scanf("%d",&t);
    int cnt = 1;
    while(t--) {
        int k;
        scanf("%d",&k);
        int Min = 101, Max = -1,gap = 0;
        vector<int> v;
        for(int i=0;i<k;i++){
            int num;
            scanf("%d",&num);
            Min = min(Min,num);
            Max = max(Max,num);
            v.push_back(num);
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size()-1;i++){
            gap = max(gap, v[i]-v[i+1]);
        }
        printf("Class %d\n",cnt++);
        printf("Max %d, Min %d, Largest gap %d\n",Max,Min,gap);
    }
    return 0;
}