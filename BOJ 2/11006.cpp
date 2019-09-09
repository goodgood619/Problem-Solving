#include <stdio.h>
#include <algorithm>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d %d\n",2*m-n , n - m);
	}
	return 0;
}