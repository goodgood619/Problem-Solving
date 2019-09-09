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
typedef pair<pair<int, int>, pair<int,int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n;
int arr[500005];
int idx[500005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	stack<P> st;
	vector<int> v;
	st.push({ arr[n],n });
	for (int i = n - 1; i >= 1; i--) {
		int here = arr[i];
		if (st.top().first < here) {
			int index = i;
			while (!st.empty() && st.top().first < here) {
				idx[st.top().second] = i;
				st.pop();
			}
			st.push({ here,i });
		}
		else st.push({here, i});
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", idx[i]);
	}
	return 0;
}