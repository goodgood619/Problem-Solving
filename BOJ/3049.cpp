#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	printf("%d\n", n*(n - 1)*(n - 2)*(n - 3) / 24);
	return 0;
}