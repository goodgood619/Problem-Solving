#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> garopq;
priority_queue<ll, vector<ll>, greater<ll>> seropq;
ll arrx[25005];
ll arry[25005];
ll diffx[25005];
ll diffy[25005];
int n, m;
ll A, B;
int main() {
	scanf("%lld%lld%d%d", &A, &B, &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arrx[i]);
	}
	arrx[n + 1] = A;
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &arry[i]);
	}
	arry[m + 1] = B;
	sort(arrx, arrx + n + 1);
	sort(arry, arry + m + 1);
	for (int i = 0; i <= n; i++) {
		diffx[i] = arrx[i + 1] - arrx[i];
		seropq.push(diffx[i]);
	}
	for (int i = 0; i <= m; i++) {
		diffy[i] = arry[i + 1] - arry[i];
		garopq.push(diffy[i]);
	}
	ll total = 0;
	bool check = false;
	int p = n + 1;
	int q = m + 1;
	while (!garopq.empty() &&!seropq.empty()){
		ll garotop = garopq.top();
		ll serotop = seropq.top();
		if (!check){
			total += garotop * (p-1);
			total += serotop * (q-1);
			garopq.pop();
			seropq.pop();
			check = true;
			continue;
		}
		if (garotop < serotop){
			total += garotop *(p-1);
			garopq.pop();
			q--;
		}
		else if (garotop > serotop){
			total += serotop *(q-1);
			seropq.pop();
			p--;
		}
		else if (garotop == serotop){
			total += garotop * (p-1);
			garopq.pop();
			q--;
		}
	}
	printf("%lld\n", total);
	return 0;
}