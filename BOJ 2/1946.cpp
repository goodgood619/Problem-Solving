#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <vector>
using namespace std;
typedef int64_t ll;
int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int n,cnt=0;
		scanf("%d", &n);
		vector<bool> visited;
		vector<pair<int, int>> arr;
		visited.assign(n, bool());
		arr.assign(n, pair<int, int>());
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &arr[i].first, &arr[i].second);
		}
		sort(arr.begin(), arr.end());
		int second = arr[0].second;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i].second < arr[i + 1].second) visited[i + 1] = true;
			else {
				if (second < arr[i + 1].second) {
					visited[i + 1] = true;
				}
				else if (second > arr[i + 1].second) {
					second = arr[i + 1].second;
				}
			}
		}
		for (int i = 0; i < visited.size(); i++) {
			if (!visited[i]) cnt++;
		}
		printf("%d\n", cnt);
		arr.clear();
		visited.clear();
	}
	return 0;
}