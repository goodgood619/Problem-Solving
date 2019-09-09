#include <stdio.h>
#include <algorithm>
using namespace std;
bool visited[31];
int big;
int small = 330;
bool chk;
int main() {
	for (int i = 1; i <= 28; i++){
		int count;
		scanf("%d", &count);
		visited[count] = true;
	}
	for (int i = 1; i <= 30; i++) {
		if (!visited[i]) {
			if (small>i && !chk) {
				small = i;
				chk = true;
				continue;
			}
			else if (chk)
			{
				big = i;
				continue;
			}
		}
	}
	printf("%d\n", small);
	printf("%d\n", big);
	return 0;
}