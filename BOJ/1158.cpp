#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n, m;
queue <int> q;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) { q.push(i);}
	int p = 1;
	printf("<");
	while (!q.empty()) {
		if (p != m) {
			int front = q.front();
			q.pop();
			q.push(front);
			p++;
		}
		else {
			if (q.size() != 1) printf("%d, ",q.front());
			else printf("%d", q.front());
			q.pop();
			p = 1;
		}
	}
	printf(">\n");
	return 0;
}