#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
using namespace std;
typedef long long ll;
#define INF 1e9
typedef pair<int, int> P;
int n,s,ans;
int arr[25];
bool visited[25];
void go(int index, int cnt, int sum, int depth) {
	if (cnt == depth){
		if (sum == s) ans++;
		return;
	}
	for (int i = index; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(i + 1, cnt + 1, sum + arr[i], depth);
			visited[i] = false;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf("%d%d", &n,&s);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }
	for (int i = 1; i <= n; i++) {
		go(0, 0,0,i);
	}
	printf("%d\n", ans);
	return 0;
}