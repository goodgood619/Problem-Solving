#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a,b;
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}