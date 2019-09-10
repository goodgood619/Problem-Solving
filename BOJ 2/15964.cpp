#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a, b;
int main(){
	scanf("%lld%lld", &a, &b);
	printf("%lld\n", (a + b)*(a - b));
	return 0;
}