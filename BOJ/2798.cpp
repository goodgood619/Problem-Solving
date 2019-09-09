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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, k,Max;
vector<int> v,temp;
bool visited[105];
void go(int index, int cnt, int hab) {
	if (cnt == 3) {
		int sum = 0;
		for (int i = 0; i < temp.size(); i++) {
			sum += temp[i];
		}
		if (sum > hab) return;
		else Max = max(Max, sum);
		return;
	}
	for (int i = index; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(i + 1, cnt + 1, hab);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	go(0, 0, k);
	printf("%d\n", Max);
	return 0;
}