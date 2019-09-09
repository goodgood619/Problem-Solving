#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int arr[105];
int n;
vector<int> ans;
vector<int> real;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]); }
	sort(arr + 1, arr + n + 1);
	int diff = arr[n] - arr[1];
	int p = 2;
	ans.push_back(diff);
	for (int i = 2; i <= sqrt(diff); i++) {
		if (diff%i == 0) {
			int high = diff / i;
			int low = i;
			if (high != low) {
				ans.push_back(high);
				ans.push_back(low);
			}
			else ans.push_back(low);
		}
	}
	sort(ans.begin(), ans.end());
	// 각각의 약수에대해서 나누어보고, 가장작은수의 mod로 보다 당연히 

	for (int i = 0; i < ans.size(); i++) {
		int ahr = ans[i];
		int sk = arr[1] % ahr;
		bool check = false;
		for (int i = 2; i <= n; i++) {
			if (sk == arr[i] % ahr) continue;
			else {
				check = true;
				break;
			}
		}
		if (!check) {
			real.push_back(ahr);
		}
	}
	for (int i = 0; i < real.size(); i++) { printf("%d ", real[i]); }
	return 0;
}