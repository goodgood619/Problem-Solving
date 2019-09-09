#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int t;
bool visited[105];
int main(){
	scanf("%d",&t);
	while (t--){
		vector<int> arr;
		vector<int> ans;
		int n;
		bool no = false;
		memset(visited, false, sizeof(visited));
		scanf(" %d", &n);
		for (int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);
			arr.push_back(num);
		}
		int length = arr.size();
		for (int i = length - 1; i >= 0; i--){
			int cnt = arr[i];
			int score = i + 1 - cnt;
			int idx;
			for (int j= n; j>= 1; j--) {
				if (visited[j]) continue;
				else{
					score--;
					if (score == 0){
						idx = j;
						break;
					}
				}
			}
			if (visited[idx]) {
				no = true;
				break;
			}
			visited[idx] = true;
			ans.push_back(idx);
		}
		if (no) printf("IMPOSSIBLE\n");
		else {
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++) {
				printf("%d ", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}