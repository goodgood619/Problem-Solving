#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
#include <functional>
using namespace std;
int n,ans,length,start2;
priority_queue<int, vector<int>,greater<int>> minheap;
priority_queue<int, vector<int>> maxheap;
// 작은값을 최대힙에 넣는다. 큰값을 최소힙에 넣는다.
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (maxheap.empty()) maxheap.push(num);
		else if (maxheap.top() < num) minheap.push(num);
		else maxheap.push(num);

		if (maxheap.size() < minheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		else if(maxheap.size()>minheap.size()+1){
			minheap.push(maxheap.top());
			maxheap.pop();
		}
		printf("%d\n", maxheap.top());
	}
	return 0;
}