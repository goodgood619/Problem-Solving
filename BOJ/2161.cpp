#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int arr[1001];
int n,cnt;
bool flag;
queue <int> q;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		q.push(i);
	}
	while (cnt!=n){
		if (!flag) {
			printf("%d ", q.front());
			q.pop();
			flag = true;
			cnt++;
		}
		else {
			int front = q.front();
			q.push(front);
			q.pop();
			flag = false;
		}
	}
	return 0;
}