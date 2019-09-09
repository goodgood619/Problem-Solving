#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iostream>
#include <functional>
#include <deque>
#include <math.h>
#include <string>
#include <climits>
using namespace std;
int n,m;
#define INF 1e9
int isprime[10005];
vector<int> temp;
void go() {

	for (int i = 2; i <= sqrt(10000); i++){
		if (isprime[i] == 0) continue;
		for (int j = i*i; j <= 10000; j += i) {
			isprime[j] = 0;
		}
	}
}
int main(){
	int t;
	for (int i = 2; i <= 10000; i++)isprime[i] = i;
	go();
	for (int i = 2; i <= 10000; i++) {
		if (isprime[i] != 0) temp.push_back(isprime[i]);
	}
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int left = 0;
		int right = 1;
		int sum = 0;
		int length = temp.size();
		vector<int>::iterator it;
		int diff = 1e9;
		for (int i = 0; i < length; i++) {
			it = lower_bound(temp.begin(), temp.end(), n - temp[i]);
			if (*it + temp[i] == n) {
				if (diff > abs(*it - temp[i])) {
					diff = abs(*it - temp[i]);
					left = min(*it, temp[i]);
					right = max(*it, temp[i]);
				}
			}
		}
		printf("%d %d\n", left, right);

	}
	
	return 0;
}