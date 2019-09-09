#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
stack <int> st;
int main(){
	st.push(-1);
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++){
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (st.top() == -1) break;
			else st.pop();
		}
		else st.push(num);
	}
	while (st.top() != -1) {
		sum += st.top();
		st.pop();
	}
	printf("%d\n", sum);
	return 0;
}