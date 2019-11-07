#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };

int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    if(x<n || 26*n <x) {printf("!\n");
    }
    else{
        string ret;
        for(int i= 0 ;i<n;i++) ret += 'A';
        x -= n;
        for(int i= n-1; i>=0; i--) {
            int t = min(x,25);
            ret[i] += t;
            x -= t;
        }
        printf("%s\n",ret.c_str());
    }
 	return 0;
}