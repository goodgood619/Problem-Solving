#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll go(ll x,ll y,ll n){
    ll m = x+y;
    if (m < n) {
			if (m % 2 == 0) return 1 + m * (m + 1) / 2 + x;
            else return 1 + m * (m + 1) / 2 + y;
		}
		else {
			if (m % 2 == 0) return n * n - ((n - 1) * 2 - m) * ((n - 1) * 2 + 1 - m) / 2 - (n - 1) + x;
			else return n * n - ((n - 1) * 2 - m) * ((n - 1) * 2 + 1 - m) / 2 - (n - 1) + y;
    }
}
int main() {
    ll n;
    int k;
    scanf("%lld%d",&n,&k);
    ll x =0 , y=0,sum = 1 ;
    for(int i =0 ; i<k;i++){
        char c;
        scanf(" %c",&c);
        if(c=='U') y--;
        if(c=='D') y++;
        if(c=='L') x--;
        if(c=='R') x++;
        sum += go(x,y,n);
    }
    printf("%lld\n",sum);
 	return 0;
}