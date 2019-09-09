#include <cstdio>
#include <algorithm>
using namespace std;
int n,cnt;
int main(){
	scanf("%d", &n);
	long long left = 1;
	long long right = 1;
	long long sum = 0;
	while (left <= right) {
		if (left > n) break;
		if (sum < n) {
			sum += right;
			right++;
		}
		else{
			if (sum == n) cnt++;
			sum -= left;
			left++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}