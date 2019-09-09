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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
vector<int> a;	
bool visited[55];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		a.push_back(num);
	}
	vector<int> temp = a;
	vector<int> ans;
	ans.resize(1005);
	sort(temp.begin(), temp.end());
	for (int i = 0; i < a.size(); i++) {
		int num = a[i];
		for (int j = 0; j < temp.size(); j++) {
			if (num == temp[j] && !visited[j]) {
				printf("%d ", j);
				visited[j] = true;
				break;
			}
		}
	}
	return 0;
}