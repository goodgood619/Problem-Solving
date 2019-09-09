#include <stdio.h>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
int n, t;
long long Max;
long long height[1000002];
int main() {
		scanf("%d", &n);
		Max = 0;
		memset(height, 0, sizeof(height));
		for (int i = 1; i <= n; i++)
			scanf("%lld", &height[i]);
		stack <long long> st;
		// 스택의 높이가 더클때까지 계속 pop하면서 넓이를 구한다.
		// 만약 입력되는 높이가 더 크다면 확장할수있으므로, 계속 push를 한다.
		for (int i = 0; i <= n + 1; i++) {
			while (!st.empty() && height[i] < height[st.top()]) {
				int index = st.top();
				st.pop();
				Max = max((i - st.top() - 1)*height[index], Max);
			}
			st.push(i);
		}
		printf("%lld\n", Max);
	return 0;
}