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
priority_queue<int, vector<int>,greater<int>> pq;
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		pq.push(num);
	}
	int sum = 0;
	while (1){
		if (pq.size() == 1) break;
		else{
			int top1 = pq.top();
			pq.pop();
			int top2 = pq.top();
			pq.pop();
			pq.push(top1 + top2);
			sum += (top1 + top2);
		}
	}
	printf("%d\n", sum);
	return 0;
}