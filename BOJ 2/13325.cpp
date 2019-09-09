#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
using namespace std;
typedef long long ll;
int n;
ll dp[1 << 22];
ll Max[1 << 22];
ll node[1 << 22];
int main(){
	scanf("%d", &n);
	int temp = pow(2, n + 1) - 1;
	for (int i = 2; i <= temp; i++){
		scanf("%lld", &node[i]);
	}
	for (int i = pow(2, n) - 1;i>0;i--){
		// Max[i]는 왼쪽자식에서부터 리프노드까지의 합+왼쪽자식 or 오른쪽자식+리프노드까지의 합중에서 max를 취한다.
		Max[i] = max(Max[2 * i] + node[2 * i], Max[2 * i + 1] + node[2 * i + 1]);
		// dp는 결국 왼쪽자식의합과 오른쪽자식의 합을 더하는데, 분명히 왼쪽 자식과 오른쪽자식의 합이 다를수있기때문에
		// 그 차이값까지 더해줘야 dp가 올랍르게 갱신이 될수 있다.
		dp[i] = dp[2 * i] + dp[2 * i + 1] + Max[i] - Max[i * 2] + Max[i] - Max[i * 2 + 1];
	}
	printf("%lld\n", dp[1]);
	return 0;
}