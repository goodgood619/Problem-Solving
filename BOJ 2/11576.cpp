#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
int n, m,cnt;
stack<int> st;
void go(int sum) {
	if (sum < m) {
		st.push(sum);
		return;
	}
	else {
		go(sum / m);
		go(sum%m);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%d", &cnt);
	int sum = 0;
	for (int i = 1; i <= cnt; i++){
		int num;
		scanf("%d", &num);
		sum += (num)*pow(n,cnt-i);
	}
	go(sum);
	vector<int> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}