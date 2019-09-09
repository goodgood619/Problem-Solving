#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
int t;
int parent[20005];
int cost[20005];
int find(int u) {
	if (parent[u] == u) return u;
	else {
		int temp = find(parent[u]);
		cost[u] += cost[parent[u]];
		parent[u] = temp;
		return parent[u];
	}
}
void uni(int u, int v){
	cost[u]=abs(u - v) % 1000;
	parent[u] = v;
}
int main(){
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(parent, 0, sizeof(parent));
		memset(cost, 0, sizeof(cost));
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		while (1) {
			char c;
			scanf(" %c", &c);
			if (c == 'O') break;
			else if(c=='I'){
				int a, b;
				scanf("%d%d", &a, &b);
				uni(a, b);
			}
			else if (c == 'E') {
				int here;
				scanf("%d", &here);
				find(here);
				printf("%d\n", cost[here]);
			}
		}
	}
	return 0;
}