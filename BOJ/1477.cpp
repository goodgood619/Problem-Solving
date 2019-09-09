#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, k, l;
vector<int> v,v2;
int main(){
	scanf("%d%d%d", &n, &k, &l);
	v.push_back(0);
	v.push_back(l);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int left = 0;
	int right = l;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < v.size()-1; i++) {
			cnt += ((v[i+1]-v[i]-1) / mid);
		}
		if (cnt >k) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n",left);
	return 0;
}