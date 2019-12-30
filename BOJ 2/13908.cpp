#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
void go(int cnt,vector<int> &temp,int depth,vector<int> &v,int &ans){
    if(cnt == depth) {
        bool check = true;
        for(int i=0;i<v.size();i++) {
            int ok = 0;
            for(int j=0;j<temp.size();j++){
                if(v[i] == temp[j]) {
                    ok = 1;
                    break;
                }
            }
            if(!ok) return;
        }
        ans++;
        return;
    }

    for(int i=0;i<10;i++) {
        temp.push_back(i);
        go(cnt+1,temp,depth,v,ans);
        temp.pop_back();
    }
}
int main() {
    Int n,m;
    scanf("%d%d",&n,&m);
    vector<int> v;
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        v.push_back(num);
    }
    vector<int> temp;
    sort(v.begin(),v.end());
    int ans = 0;
    go(0,temp,n,v,ans);
    printf("%d\n",ans);
    return 0;
}