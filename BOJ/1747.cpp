#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gox[4] = {0,0,-1,1};
int goy[4] = {1,-1,0,0};
int main() {
    int n;
    scanf("%d",&n);
    int *notprime = new int[1004000];
    notprime[1] = 1;
    for(int i = 2; i<=1004000;i++) notprime[i] = 0;

    for(int i = 2; i<=sqrt(1004000) ; i++){
        for(int j = i*i ; j<=1004000 ;j+=i){
            notprime[j] = 1;
        }
    }
    int ok = 0;
    for(int i = n ;;i++) {
        if(notprime[i] != 0 ) continue;
        string s = to_string(i);
        int temp = 0 ;
        for(int j =0,k=s.size()-1 ;j<=k;j++,k--){
            if(s[j] != s[k]) {
                temp++;
                break;
            }
        }
        if(!temp){
            ok = 1;
        }
        if(ok == 1){
            printf("%d\n",i);
            break;
        }
    }
    delete[] notprime;
    return 0;
}