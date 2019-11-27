#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[8] = {0,0,-1,1,1,1,-1,-1};
int goy[8] = {1,-1,0,0,-1,1,-1,1};
int main() {
    int n;
    scanf("%d",&n);
    vector <int> v;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    int here = 0,cnt = 0;
    for(int i=v.size()-1;i>=0;i--){
        if(here<v[i]){
            here = v[i];
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}