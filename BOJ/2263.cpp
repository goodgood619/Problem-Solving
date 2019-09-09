#include <cstdio>
#include <algorithm>
using namespace std;
int leftcnt[100003];
int inorder[100003];
int postorder[100003];
int n;
void go(int inst, int inen, int post, int poen){
	if (inst > inen || post > poen) return;
	int root = postorder[poen];
	printf("%d ", root);
	int rootindex=leftcnt[root];
	int leftCnt = rootindex - inst;
	go(inst, rootindex - 1,post,post+leftCnt-1);
	go(rootindex + 1, inen, post +leftCnt, poen - 1);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &inorder[i]);}
	for (int i = 1; i <= n; i++) { scanf("%d", &postorder[i]);}
	for (int i = 1; i <= n; i++) { leftcnt[inorder[i]] = i;}
	go(1, n, 1, n);
	return 0;
}