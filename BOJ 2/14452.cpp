#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int n, t;
int ti[100005];
bool ok(int left){
	priority_queue<int, vector<int>, greater<int>> pq;
	int firsttime = 0;
	int k = left;
	for (int i = 1; i <= n; i++){
		if (pq.size()==k){
			firsttime = pq.top();
			pq.pop();
		}
		if (firsttime + ti[i]>t){
			return false;
		}
		pq.push(firsttime + ti[i]);
	}
	return true;
}
int main(){
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ti[i]);
	}
	int left = 1;
	int right = 10000000;
	while (left <=right) {
		int mid = (left + right) / 2;
		if (!ok(mid)) {
			left = mid + 1;
		}
		else right = mid-1;
	}
	printf("%d\n",left);
	return 0;
}