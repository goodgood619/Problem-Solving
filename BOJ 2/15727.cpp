#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define mod 1000000
int main(){
	int n;
	scanf("%d", &n);
	if (n % 5 == 0) printf("%d\n", n / 5);
	else printf("%d\n", n / 5 + 1);
	return 0;
}