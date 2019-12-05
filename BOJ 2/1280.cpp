#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void update(vector<ll> &fenwick,ll index,ll value){
    while(index<=fenwick.size()) {
        fenwick[index] += value;
        index += (index & -index);
    }
}
ll query(vector<ll> &fenwick, ll index){
    ll sum = 0;
    while(index>0){
        sum += fenwick[index];
        index -= (index & -index);
    }
    return sum;
}
ll sum(vector<ll> &fenwick, int s, int e){
    if(s >e ) return 0;
    return query(fenwick,e) - query(fenwick,s-1);
}
int main() {
    ll mod = 1000000007;
    ll MAX = 200020;
    int n;
    scanf("%d",&n);
    vector<ll> fenwickdist;
    vector<ll> fenwickcnt;
    fenwickdist.assign(MAX,0);
    fenwickcnt.assign(MAX,0);
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ll tmp = 0;
        ll num;
        scanf("%lld",&num);
        num++;
        if(i == 1){
            update(fenwickdist,num,num);
            update(fenwickcnt,num,1);
        }
        else {
            tmp += sum(fenwickdist,num + 1, MAX) - num * sum(fenwickcnt,num+1,MAX);
            tmp += num * sum(fenwickcnt,1,num-1) - sum(fenwickdist,1,num-1);
            tmp %= mod;
            update(fenwickcnt,num,1);
            update(fenwickdist,num,num);
            ans = (ans * tmp) % mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}