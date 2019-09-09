#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
map <int, int> m;
int hab[200001];
int n, k;
long long cnt;
int main() {
	// hab[i](자체만의 경우,즉 k가될때)가 있을수있음
	m[0] = 1;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &hab[i]);
		hab[i] += hab[i - 1];
		// m[hab[i]-k]-> hab[j]의갯수>0 -> hab[j]의갯수만큼 누적적으로 더해주면된다.
		if (m[hab[i] - k]>0) {
			cnt += m[hab[i] - k];
		}
		//그런경우가아니면 그냥 m[hab[i]]-> i번째까지의 합을 갯수를 하나 증가시켜준다.
		m[hab[i]]++;
	}
	printf("%lld\n", cnt);
	return 0;
}