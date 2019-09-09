#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n;
int arr[100005];
bool visited[100005];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		visited[num] = true;
		arr[i] = num;
	}
	for (int i = 1; i <= 2*n; i++){
		if (visited[i]) continue;
		else pq.push(i);
	}

	sort(arr + 1, arr + 2 * n + 1);

	int win = 0;
	int rptr = n + 1;
	while (!pq.empty()){
			int num = arr[rptr];
			if (rptr > 2 * n) break;
			if (pq.top() > num) {
				win++;
				pq.pop();
				rptr++;
				continue;
			}
			else {
				pq.pop();
				continue;
			}
	}
	printf("%d\n", win);
	return 0;
}