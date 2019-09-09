#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[11];
int sum,Sum,ans;
int Min = 9999999;
int Min2 = 9999999;
bool check;
int main(){
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if (sum < 100) printf("%d\n", sum);
	else {
		for (int i = 1; i <= 10; i++) {
			Sum += arr[i];
			if (Sum == 100) {
				check = true;
				break;
			}
			else {
				if (abs(Sum - 100) <Min && Sum<100) {
					Min = abs(Sum - 100);
					ans = Sum;
				}
				else if (abs(Sum - 100)<=Min && Sum > 100) {
					Min = abs(Sum - 100);
					ans = 100 + Min;
				}
			}
			if (check) break;
		}
		if (check) printf("100\n");
		else printf("%d\n", ans);
	}
	return 0;
}