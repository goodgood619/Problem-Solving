#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;
int n, m;
bool visited[10];
int ans[10];
// nPm
void go(int index, int cnt, int depth) {
	if (depth == cnt){
		for (int i = 0; i <n; i++){
			if (visited[i]) {
				printf("%d ", i+1);
			}
		}
		printf("\n");
		return;
	}
	for (int i = index; i < n; i++){
		if (!visited[i]) {
			visited[i] = true;
			go(i+1,cnt + 1,depth);
			visited[i] =false;
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	go(0, 0, m);
	return 0;
}