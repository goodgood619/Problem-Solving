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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<ll, int> P;
typedef pair<int, pair<int, ll>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,ans1,ans2;
bool ok;
vector<int> v,temp;
bool visited[11];
void go(int index, int cnt, int depth) {
	if (ok) return;
	if (cnt == depth){
		int check[10] = { 0, };
		int a = 0;
		for (int i = 0; i < temp.size(); i++) {
			a += temp[i]*pow(10,temp.size() - 1 - i);
		}
		int q = a;
		while (a > 0) {
			check[a % 10]++;
			a /= 10;
		}
		int b = n - q;
		int p = b;
		while (b > 0) {
			check[b % 10]++;
			b /= 10;
		}
		for (int i = 0; i < 10; i++) {
			if (check[i] >= 2) return;
		}
		if (q <= 0 || p <= 0) return;
		ok = true;
		ans1 = q;
		ans2 = p;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(index + 1, cnt + 1, depth);
			visited[i] = false;
			temp.pop_back();
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) v.push_back(i);
	v.push_back(0);
	for (int i = 1; i <=5;i++) {
		go(0, 0, i);
	}
	if (!ok) printf("-1\n");
	else printf("%d + %d\n", ans1,ans2);
	return 0;
}