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
typedef pair<char, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m,t;
string a, b;
int main()
{
	scanf("%d%d", &n, &m);
	cin >> a >> b;
	scanf("%d", &t);
	vector<P> v;
	for (int i = a.size()-1; i >=0; i--) {
		v.push_back({ a[i],1 });
	}
	for (int i = 0; i < b.size(); i++) {
		v.push_back({ b[i],2 });
	}

	for (int i = 1; i <= t; i++) {
		for (int j = 0; j < v.size()-1; j++) {
			if (v[j].second == 1 && v[j + 1].second == 2) {
				swap(v[j], v[j + 1]);
				j++;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%c", v[i].first);
	}
	return 0;
}
