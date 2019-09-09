#include <cstdio>
#include <algorithm>
using namespace std;
int m;
int main(){
	scanf("%d", &m);
	int ball = 1;
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (first == ball) {
			int temp = second;
			second = ball;
			ball = temp;
		}
		else if (second == ball) {
			int temp = first;
			first = ball;
			ball = temp;
		}
		else {
			continue;
		}
	}
	printf("%d\n", ball);
	return 0;
}