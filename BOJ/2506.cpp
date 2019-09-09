#include <stdio.h>
#include <algorithm>
using namespace std;
int n,total;
int arr[101];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int score = 0;
	for (int i = 1; i <= n; i++){
		if (arr[i] == 1) {
			score++;
			total += score;
		}
		else if (arr[i] == 0) {
			score = 0;
		}
	}
	printf("%d\n", total);
	return 0;
}
