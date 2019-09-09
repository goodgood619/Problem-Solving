#include <cstdio>
#include <algorithm>
using namespace std;
int n, cnt, p,sum;
bool visited[201];
int main() {
	scanf("%d", &n);
	if (n == 0) printf("1\n");
	else{
		visited[n] = true;
		while (1){
			int a, b, c;
			if (n < 10) {
				a = 0;
				b = n;
				c = a + b;
				if (c >= 10) sum = b * 10 + c % 10;
				else sum = b * 10 + c;
				cnt++;
				n = sum;
			}
			else {
				a = n / 10;
				b = n % 10;
				c = a + b;
				if (c >= 10) sum = b * 10 + c % 10;
				else sum = b * 10 + c;
				cnt++;
				n = sum;
			}
			if (visited[n]) break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
