#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
vector<vector<int>> a,depth;
int leftcnt[1001];
int inorder[1001];
int preorder[1001];
void dfs(int prest,int preend,int inst,int inend) {
	if (prest > preend || inst > inend) return;
	int root = preorder[prest];
	int rootindex = leftcnt[root];
	int cnt = leftcnt[root] - inst;
	dfs(prest+1,prest+cnt,inst,rootindex-1); //왼쪽이동
	dfs(prest+cnt+1,preend,rootindex+1,inend); // 오른쪽이동
	printf("%d ", root);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &preorder[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &inorder[i]);
		for (int i = 1; i <= n; i++) leftcnt[inorder[i]] = i;
		dfs(1, n, 1, n);
		printf("\n");
	}
	return 0;
}