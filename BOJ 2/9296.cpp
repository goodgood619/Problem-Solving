#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    int cnt = 1;
    while(t--){
        int n;
        scanf("%d",&n);
        string s1,s2;
        cin >> s1 >> s2;
        int incorrect = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i] != s2[i]) incorrect++;
        }
        printf("Case %d: %d\n",cnt++,incorrect);
    }
    return 0;
}