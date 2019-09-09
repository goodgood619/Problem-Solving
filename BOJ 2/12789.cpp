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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n;
int arr[1005];
stack<int> st;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int start = 1;
	for (int i = 1; i <= n; i++) {
		if (start == arr[i]) {
			start++;
			continue;
		}
		else {
			while (!st.empty() && st.top() == start) {
				st.pop();
				start++;
			}
			st.push(arr[i]);
		}
	}
	int no = 0;
	while (!st.empty()) {
		int num = st.top();
		if (start == num) {
			st.pop();
			start++;
		}
		else {
			no = 1;
			break;
		}
	}
	no == 1 ? printf("Sad\n") : printf("Nice\n");
	return 0;
}