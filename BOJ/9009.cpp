#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int t;
ll fibo[5000];
int main(){
	scanf("%d",&t);
	fibo[0] = 0;
	fibo[1] = 1;
	for (int i = 2;; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		if (fibo[i] >= 1e9) break;
	}

	while (t--){
		int n;
		scanf("%d", &n);
		int Max = 45;
		vector<int> ans;
		for (int i = Max; i >= 1; i--) {
			if (fibo[i] > n) { continue;}
			else {
				n -= fibo[i];
				ans.push_back(fibo[i]);
				if (n == 0) break;
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) { printf("%d ", ans[i]);}
		printf("\n");
		
	}
	return 0;
}