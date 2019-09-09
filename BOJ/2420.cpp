#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll a, b;
int main(){
	scanf("%lld%lld", &a,&b);
	printf("%lld\n", abs(a - b));
	return 0;
}