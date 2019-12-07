#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--){
        int yonsei =0, korea =0;
        for(int i=0;i<9;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            yonsei += a, korea += b;
        }
        if(yonsei == korea) printf("Draw\n");
        else if(yonsei>korea) printf("Yonsei\n");
        else printf("Korea\n");
    }
    return 0;
}