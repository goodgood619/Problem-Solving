#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			if (pq.size() < n) pq.push(num);
			else if (num > pq.top()) {
				pq.pop();
				pq.push(num);
			}
		}
	}
	printf("%d\n", pq.top());
	return 0;
}