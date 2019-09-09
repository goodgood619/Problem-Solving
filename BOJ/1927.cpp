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
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			if (pq.empty()) printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}