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
#define mod 1000000007
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int main() {
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	vector<PP> v;
	for (int i = 1; i <= n; i++) {
		int first, second, third;
		scanf("%d%d%d", &first, &second, &third);
		v.push_back({ { first,second }, third });
	}
	int Max = 0;
	for (int i = 1; i <= 3; i++) {
		int pebble = i;
		int check[4] = { 0, };
		check[pebble] = 1;
		int cnt = 0;
		for (int j = 0; j < v.size(); j++) {
			int first = v[j].first.first, second = v[j].first.second,third=v[j].second;
			int temp = check[first];
			check[first] = check[second];
			check[second] = temp;
			if (check[third] == 1) cnt++;

		}
		Max = max(Max, cnt);
	}
	printf("%d\n", Max);
	return 0;
}