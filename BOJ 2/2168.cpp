#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b%a,a);
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    int res= gcd(x,y);
    printf("%d",res*(x/res+y/res-1));
    return 0;
}