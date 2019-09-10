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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m;
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &m);
	vector<pair<int,int>> v;
	for (int i = 1; i <= n; i++) {
		int front, back;
		scanf("%d%d", &front, &back);
		v.push_back({ front,back });
	}
	vector<pair<int,int>> temp;
	for (int i = 0; i < v.size(); i++) {
		temp.push_back({ v[i].first,0 });
	}
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j].first <= num) {
				if (temp[j].second == 0) {
					temp[j].first = v[j].second;
					temp[j].second = 1;
				}
				else {
					temp[j].first = v[j].first;
					temp[j].second = 0;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < temp.size(); i++) {
		sum += temp[i].first;
	}
	printf("%d\n", sum);
	return 0;
}