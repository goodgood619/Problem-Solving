#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;
int n, k;
vector<char> arr;
map<int, int> m;
map<int, int> m2;
bool visited[500005];
stack<char> st;
int Max;
int main() {
	scanf("%d%d", &n, &k);
	int index;
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		arr.push_back(c);
	}
	int length = arr.size();
	st.push(arr[0]);
	for (int i = 1; i < length; i++){
		char next = arr[i];
		if (k == 0) {
			st.push(next);
			continue;
		}
		while (!st.empty() && st.top() < next && k>0){
			st.pop();
			k--;
		}
		st.push(next);
	}
	while (k > 0) {
		st.pop();
		k--;
	}
	vector<char> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)printf("%c", ans[i]);
	return 0;
}