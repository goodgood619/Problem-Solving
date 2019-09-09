#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;
int n, p;
int arr[100001];
char c[250001];
stack <int> st;
int k = 1;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); }
	st.push(0);
	int Max = n;
	for (int i = 1; i <= n; i++) {
		int num = arr[i];
		while (num != st.top() && k <= Max) {
			st.push(k);
			c[p++] = '+';
			k++;
		}
		while (num == st.top()) {
			st.pop();
			c[p++] = '-';
			//if (st.empty()) break;
		}
	}
	if (st.top() == 0) {
		for (int i = 0; i < p; i++) {
			printf("%c\n", c[i]);
		}
	}
	else printf("NO\n");
	return 0;
}