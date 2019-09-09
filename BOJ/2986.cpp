#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int n,idx;
bool check;
int main(){
	scanf("%d", &n);
		for (int i=sqrt(n); i>=2;i--) {
			if (n%i== 0) {
				idx = i;
				check = true;
			}
			else{
				continue;
			}
		}
		if (!check) printf("%d\n", n - 1);
		else {
			int real= n / idx;
			printf("%d\n", n -real);
		}
	return 0;
}