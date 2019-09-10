#include <cstdio>
#include <algorithm>
using namespace std;
int n,sum;
int main(){
	scanf("%d", &n);
	for (int i = n; i >= 1; i--) {
		int c, gob;
		scanf("%d%d", &c, &gob);
		sum += (c*gob);
	}
	printf("%d\n", sum);
	return 0;
}