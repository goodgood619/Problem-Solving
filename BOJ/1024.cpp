#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n,l;
bool check;
typedef long long ll;
vector<int> temp;
int main(){
	scanf("%d%d", &n, &l);
	for (int i = l; i <= 100; i++){
		for (ll j = n / i - i; j <= n; j++) {
			ll m = j -i+1;
			if(m<0) continue;
			ll diff = j*(j + 1) / 2 -( m*(m-1) / 2);
			if (diff > n) break;
			if (diff == n) {
				for (ll k = m; k <= j; k++) {
					printf("%lld ", k);
				}
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
