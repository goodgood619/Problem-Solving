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
#include <math.h>
using namespace std;
typedef long long ll;
vector<ll> p;
vector<ll> q;
int n;
map<int, int> m;
int main(){
	scanf("%d", &n);
	int sum = 0;
	int temp = n;
	bool ok = false;
	m[temp]++;
	while (1) {
		int p = temp;
		while (p > 0) {
			sum += (p % 10)*(p%10);
			p /= 10;
		}
		if (sum == 1) {
			ok = true;
			break;
		}
		if (m.count(sum) != 0) break;
		m[sum]++;
		temp = sum;
		sum = 0;
	}
	if (ok) printf("HAPPY\n");
	else printf("UNHAPPY\n");
	return 0;
}