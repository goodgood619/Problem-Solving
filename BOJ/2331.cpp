#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int visit[1000000];
int A, P;
int cnt;
int b = 0;
void bfs(int A, int P) {
	visit[A] += 1;
	b = 0;
	int val = 0;
	while (A){
		val+=pow(A % 10, P);
		A /=10;
	}
	if (visit[val] != 2)
		bfs(val, P);
}
int main() {
	scanf("%d %d", &A, &P);

	bfs(A, P);
	for (int i = 1; i <= 1000000; i++)
	{
		if (visit[i] == 1)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}