#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#define mod 1000000007
using namespace std;
typedef long long ll;
int t,n;
long long sum = 1;
int main(){
	scanf("%d", &t);
	while (t--){
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		sum = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			ll a;
			a %= mod;
			scanf("%lld", &a);
			pq.push(a);
		}
		if (n == 1) printf("1\n");
		else{
			while (1) {
				if (pq.size() == 1) break;
				ll first = pq.top();
				pq.pop();
				ll second = pq.top();
				pq.pop();
				ll Push = ((first%mod)*(second%mod));
				pq.push(Push);
				sum=((sum%mod)*(Push%mod))%mod;
			}
			printf("%lld\n", sum%mod);
		}
	}
	return 0;
}