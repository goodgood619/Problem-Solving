
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
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll fact[25];
int n,what;
ll k;
vector<int> v,temp;
bool visited[25];
void go(int p, ll k) {
	ll here = fact[p - 1];
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) temp.push_back(i);
		}
		for (int i = 0; i < temp.size(); i++) {
			printf("%d ", temp[i]);
		}
		exit(0);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		if (k <=here) {
			visited[i] = true;
			temp.push_back(i);
			go(p - 1, k);
		}
		else k -= here;
	}
}
void go2(int index,int s,ll sum) {
	if (index == v.size()) {
		printf("%lld\n", sum);
		exit(0);
	}
	ll p = fact[s - 1];
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		if (v[index] == i) {
			visited[i] = true;
			go2(index + 1, s-1,sum);
		}
		else sum += p;
	}
}
int main() {
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 20; i++) {
		fact[i] = i*fact[i - 1];
	}
	scanf("%d", &n);
	scanf("%d", &what);
	if (what == 1) {
		scanf("%lld", &k);
		go(n, k);
	}
	else {
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}
		go2(0,n,1);
	}
	return 0;
}