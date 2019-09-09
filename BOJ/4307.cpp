
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		vector<int> arr;
		int l, n;
		scanf("%d%d", &l, &n);
		int mid = l / 2;
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		int longest = -1;
		int shortest =-1;
		for (int i = 0; i < arr.size(); i++) {
			longest = max(longest, abs(arr[i] - l));
			longest = max(longest, arr[i]);
			if (arr[i] > mid) {
				shortest = max(shortest, l - arr[i]);
			}
			else {
				shortest = max(shortest, arr[i]);
			}
		}
		printf("%d %d\n", shortest, longest);
	}
	return 0;
}


