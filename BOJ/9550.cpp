#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int n, k;
int candy[101];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(candy, 0, sizeof(candy));
		scanf("%d%d", &n, &k);
		int sum = 0;
		for (int i = 1; i <= n; i++) { scanf("%d", &candy[i]);}
		for (int i = 1; i <= n; i++)sum += (candy[i] / k);
		printf("%d\n", sum);
	}
	return 0;
}