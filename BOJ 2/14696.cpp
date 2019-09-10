#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int A[5];
int B[5];
int main(){
	scanf("%d", &t);
	while (t--) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		int a, b;
		scanf("%d", &a);
		for (int i = 1; i <= a; i++){
			int num;
			scanf("%d", &num);
			A[num]++;
		}
		scanf("%d", &b);
		for (int i = 1; i <= b; i++){
			int num2;
			scanf("%d", &num2);
			B[num2]++;
		}
		if (A[4] != B[4]) {
			if (A[4] > B[4]) printf("A\n");
			else if (A[4] < B[4]) printf("B\n");
		}
		else if (A[3] != B[3]) {
			if (A[3] > B[3]) printf("A\n");
			else if (A[3] < B[3]) printf("B\n");
		}
		else if (A[2] != B[2]) {
			if (A[2] > B[2]) printf("A\n");
			else if (A[2] < B[2]) printf("B\n");
		}
		else if (A[1] != B[1]) {
			if (A[1] < B[1]) printf("B\n");
			else if (A[1] > B[1]) printf("A\n");
		}
		else printf("D\n");
	}
	return 0;
}
