#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
ll isprime[1030005];
ll Min,Max;
bool check[1030005];
void go(ll here){
	ll what = sqrt(here);
	for (ll i = 2; i <= sqrt(what); i++){
		if (isprime[i] == 0) continue;
		for (ll j = i * i; j <= what; j += i) {
			isprime[j] = 0;
		}
	}
}
int main(){
	scanf("%lld%lld", &Min, &Max);
	for (ll i = 2; i <= sqrt(Max); i++){
		isprime[i] = i;
	}
	go(Max);
	vector<ll> temp;
	for (ll i = 2; i <= sqrt(Max); i++) {
		if (isprime[i] != 0) {
			temp.push_back(isprime[i]);
		}
		else continue;
	}
	memset(check, true, sizeof(check));
	for (ll i = 0; i < temp.size(); i++){
		ll p = temp[i];
		ll ahr = 1LL * p*p;
		ll j;
		// 나누어떨어지지 않는다 그러면 바로 다음에 나누어떨어지는 수를 찾자.그래서 나누고 1을더하면 바로 다음부터 나눠지는 수를 찾을수있다.
		if (Min%ahr !=0){
			j = (Min / ahr+1)*ahr;
		}
		// 나누어떨어진다 ㅇㅇ 그러면 그냥 Min부터 시작해서 거르면 된다.
		else {
			j = Min;
		}
		for (;j<=Max;j +=ahr){
			check[j - Min] = 0;
		}
	}
	int ans = 0;
	for (ll i = 0; i <Max - Min + 1; i++) {
		if (check[i]) ans++;
		else continue;
	}
	printf("%d\n", ans);
	return 0;
}