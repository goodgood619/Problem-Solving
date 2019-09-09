#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int arr[100005];
typedef long long ll;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	int left = 1;
	int right = n;
	ll sum = 0;
	vector<ll> temp;
	for (int i = 1; i <= (n / 2); i++) {
		sum = 0;
		sum += (ll)arr[left];
		sum += (ll)arr[right];
		temp.push_back(sum);
		left++;
		right--;
	}
	sort(temp.begin(), temp.end());
	printf("%lld\n", temp[0]);
	return 0;
}