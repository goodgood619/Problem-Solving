#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int,int> P;
priority_queue<P,vector<P>> pq;
int n;
int main() {
	// your code goes here
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		if(num==0){
			if(pq.empty()) printf("0\n");
			else {
				printf("%d\n",-pq.top().second);
				pq.pop();
			}
		}
		else pq.push({-abs(num),-num});
	}
	return 0;
}