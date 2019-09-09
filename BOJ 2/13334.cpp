#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
typedef pair<int, int> PP;
PP road[100005];
int n,l;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (first > second) {
			int temp = first;
			first = second;
			second = temp;
		}
		road[i].first = second;
		road[i].second = first;
	}
	sort(road + 1, road + n + 1);	
	scanf("%d", &l);
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int right = road[i].first;
		int left = road[i].second;
		pq.push(road[i].second);
		while (!pq.empty() && pq.top() < right - l) pq.pop();
		ans = max(ans,(int)pq.size());
	}
	printf("%d\n",ans);
	return 0;
}