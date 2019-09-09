#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b, ll c) {
	if (b == 0) return 1;
	else if (b % 2 == 0) return (go(a*a%c, (b) / 2, c)) %c;
	else if (b % 2 == 1)return (a*go(a*a%c, (b-1)/ 2, c))%c;
}
int main(){
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld\n",go(a, b, c));
	return 0;
}