#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(vector<ll> &fenwick,int index,ll diff) {
    while(index<fenwick.size()) {
        fenwick[index] += diff;
        index +=(index & -index);
    }
}
ll sum(vector<ll> &fenwick,int index){

    ll temp = 0;
    while(index>0){
        temp += fenwick[index];
        index -=(index & -index);
    }
    return temp;
}
int main() {
    vector<ll> fenwick;
    vector<ll> arr;
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    fenwick.assign(n+1,0);
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        update(fenwick,i,arr[i]);
    }
    for(int i=0;i<m+k;i++){
        int a;
        scanf("%d",&a);
        if(a == 1){
            int index;
            ll num;
            scanf("%d%lld",&index,&num);
            ll diff = num - arr[index];
            arr[index] = num;
            update(fenwick,index,diff);
        }
        else {
            int b,c;
            scanf("%d%d",&b,&c);
            printf("%lld\n",sum(fenwick,c)-sum(fenwick,b-1));
        }
    }
    return 0;
}