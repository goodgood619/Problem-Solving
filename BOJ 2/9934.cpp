#include <cstdio>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
int k;
int inorder[1200];
queue <int> q;
queue <int> temp;
queue <int> temp2;
int main(){
	scanf("%d", &k);
	int num=pow(2, k) - 1;
	for (int i = 1; i <= num; i++) {
		int first;
		scanf("%d", &first);
		inorder[i] = first;
	}
	int startidx =(num / 2) + 1;
	int move = pow(2, k - 2);
	if (k == 1) {
		printf("%d\n", inorder[1]);
		return 0;
	}
	q.push(startidx);
	temp.push(inorder[startidx]);
	int cnt = 0;
	while (1){
		while (!temp.empty()) {
			printf("%d ", temp.front());
			temp.pop();
		}
		printf("\n");
		if (cnt == k-1) break;
		while (!q.empty()) {
			int rootidx = q.front();
			temp2.push(rootidx - move);
			temp2.push(rootidx + move);
			q.pop();
			temp.push(inorder[rootidx - move]);
			temp.push(inorder[rootidx + move]);
		}
		while (!temp2.empty()) {
			q.push(temp2.front());
			temp2.pop();
		}
		move /= 2;
		cnt++;
	}
	return 0;
}