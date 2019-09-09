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
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n,cnt,ans=1e9;
bool broken[11];
void go(string s,int index) {
	if (index >= 6) {
		ans = min(ans, index + abs(stoi(s) - n));
		return;
	}
	if(index>0) ans = min(ans, index + abs(stoi(s) - n));
	for (int i = 0; i < 10; i++) {
		if (broken[i]) continue;
		s.push_back(i + '0');
		go(s, index + 1);
		s.pop_back();
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		int num;
		scanf("%d", &num);
		broken[num] = true;
	}
	if (n == 100) {
		printf("0\n");
		return 0;
	}
	go("",0);
	ans = min(ans, abs(n - 100));
	printf("%d\n", ans);
	return 0;
}