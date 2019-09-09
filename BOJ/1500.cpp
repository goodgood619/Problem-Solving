#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int s, k;
int arr[25];
int main(){
	scanf("%d%d", &s, &k);
	int ahr = s / k;
	int sk = s%k;
	for (int i = 1; i <= k; i++) {
		arr[i] = ahr;
	}
	if (sk == 0){
		ll gob = 1;
		for (int i = 1; i <= k; i++) {
			gob *= arr[i];
		}
		printf("%lld\n", gob);
	}
	else {
		ll gob = 1;
		for (int i = 1; i <= sk; i++) {
			arr[i] += 1;
		}
		for (int i = 1; i <= k; i++) {
			gob *= arr[i];
		}
		printf("%lld\n", gob);
	}
	return 0;
}