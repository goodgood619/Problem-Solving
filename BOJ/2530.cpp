#include <stdio.h>
#include <algorithm>
using namespace std;
int A, B, C,D;
int main() {
	scanf("%d%d%d", &A, &B,&C);
	scanf("%d", &D);
	while (D!= 0) {
		if (C+D>= 60) {
			int minute= (C+D) / 60;
			int second = (C+D) % 60;
			B+= minute;
			if (B >= 60){
				int hour=B / 60;
				B = B % 60;
				A += hour;
				if (A>= 24) {
					A = A % 24;
				}
			}
			C= second;
			D-=D;
		}
		else {
			C+=D;
			D-=D;
		}
	}
	printf("%d %d %d\n", A, B,C);
	return 0;
}