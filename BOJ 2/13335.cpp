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
int arr[1005];
int n,totalw,totall;
int main() {
	scanf("%d%d%d", &n, &totalw, &totall);
	int cnt = 0;
	int sum = 0;
	int ti = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		int weight;
		scanf("%d", &weight);
		while (1){
			ti++;
			// 만약 다리공간이 없어서 차가 진입할수 없다
			if (cnt == totalw) {
				cnt--;
				sum -= q.front();
				q.pop();
			}
			// 다리공간은 있어서, sum+weight가 totall보다 같거나 작을때 진입이 가능하다
			// 여기서 왜 else로 절대 묶으면 안되냐면, 연속적인 상황을 처리를 계속해야 하기때문에, else로 묶어버리면 걸리지를 않아서 그러함
			if (sum+weight<=totall){
				q.push(weight);
				sum += weight;
				cnt++;
				break; // 이거 중요
			}
			// 다리공간은 있고, sum+weight가 totall보다 커서 진입이 불가능할때
			else{
				q.push(0);
				sum += 0;
				cnt++;
			}
		}
	}
	printf("%d\n", ti+totalw);
	return 0;
}