#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[100003];
ll n;
int main(){
	scanf("%lld",&n);
	ll p=1;
	ll sum=1;
	int k=1;
	while(1){
		sum=(3*p*p)-(3*p)+1;
		arr[k++]=sum;
		p++;
		if(sum>=n) break;
	}
	printf("%lld\n",p-1);
	return 0;
}