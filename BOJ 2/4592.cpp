#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    while(true){
        int n;
        scanf("%d",&n);
        if(n == 0 ) break;
        vector<int> v;
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            v.push_back(num);
        }
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(i==0){
                ans.push_back(v[i]);
            }
            else {
                if(v[i]!=v[i-1]){
                    ans.push_back(v[i]);
                }
            }
        }
        for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
        printf("$\n");
    }
    return 0;
}