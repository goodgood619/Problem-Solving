#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
#include <deque>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int arr[11];
bool visited[11];
vector<int> ans;
bool ok;
void go(int index, int depth,int sum){
	if (ok) return;
	if (index > 10) return;
	if (depth == 7){
		if (sum == 100) {
			for (int i = 1; i <= 9; i++) {
				if (visited[i]) ans.push_back(arr[i]);
			}
			ok = true;
		}
		return;
	}
	for (int i = index; i <=9; i++){
		if (!visited[i]) {
			visited[i] = true;
			go(i + 1, depth + 1, sum + arr[i]);
			visited[i] = false;
		}
	}
}
int main(){
	for (int i = 1; i <= 9; i++)scanf("%d", &arr[i]);
	go(1, 0,0);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) { printf("%d\n", ans[i]); }
	return 0;
}