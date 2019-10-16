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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, int> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
int main(void) {
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		int n;
		scanf("%d", &n);
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		int start = 65;
		int cnt = 0;
		int arr[26] = { 0, };
		for (int i = 0; i < v.size(); i++) {
			arr[v[i][0]-'A']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] == 0) break;
			cnt++;
		}
		printf("#%d %d\n",Case++, cnt);
	}
	return 0;
}