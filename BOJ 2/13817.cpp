#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main()
{
    while(true) {
        int a,b;
        scanf(" %d%d",&a,&b);
        if(a==0 && b==0) break;
        int p = 2;
        map<int,int> v1,v2;
        while(true) {
            if(a==1) break;
            if(a%p==0){
                a/=p;
                if(v1.count(p)==0) v1[p]++;
                p = 2;
            }
            else p++;
        }
        p = 2;
        while(true) {
            if(b==1) break;
            if(b%p==0){
                b/=p;
                if(v2.count(p)==0) v2[p]++;
                p = 2;
            }
            else p++;
        }
        int sum1 =0 ,sum2 =0,Max1 = 0 ,Max2 = 0;
        map<int,int>::iterator it,it2;
        for(it = v1.begin();it!=v1.end();it++){
            Max1 = max(Max1,it->first);
            sum1 += it->first;
        }
        for(it2 = v2.begin();it2!=v2.end();it2++){
            Max2 = max(Max2,it2->first);
            sum2 += it2->first;
        }
        sum1-= Max1, sum2-=Max2;
        Max1-sum1>Max2-sum2?printf("a\n"):printf("b\n");
    }
    return 0;
}