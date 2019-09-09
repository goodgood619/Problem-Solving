#include <stdio.h>
#include <algorithm>
using namespace std;
int A, B,C;
int main(){
	scanf("%d%d", &A, &B);
	scanf("%d", &C);
	while (C != 0) {
		if (C + B >= 60){
			int hour = (B + C) / 60;
			int minute = (B + C) % 60;
			A+=hour;
			A = A % 24;
			B = minute;
			C -= C;
		}
		else {
			B += C;
			C -= C;
		}
	}
	printf("%d %d\n", A, B);
	return 0;
}