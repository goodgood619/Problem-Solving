#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int t;
ll n;
bool visited[10];
int main(){
	scanf("%d", &t);
	int Case = 1;
	while (t--){
		memset(visited, false, sizeof(visited));
		scanf("%lld", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", Case);
			Case++;
		}
		else{
			int cnt = 0;
			ll p = n;
			ll temp = n;
			while (1){
				while (p > 0) {
					ll mod = p % 10;
					if (!visited[mod]) {
						visited[mod] = true;
						cnt++;
					}
					p /= 10;
				}
				if (cnt != 10) {
					temp +=n;
					p = temp;
				}
				else if (cnt == 10) {
					break;
				}
			}
			printf("Case #%d: %lld\n", Case,temp);
			Case++;
		}
	}
	return 0;
}