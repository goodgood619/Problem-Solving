#include <cstdio>
#include <algorithm>
using namespace std;
int n,no;
bool check[101];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int seat;
		scanf("%d", &seat);
		if (!check[seat]) check[seat] = true;
		else no++;
	}
	printf("%d\n", no);
	return 0;
}