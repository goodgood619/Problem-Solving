#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n;
vector<P> v;
bool visited[105];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		v.push_back({ first,second });
	}
	sort(v.begin(), v.end());
	int Max = 0;
	for (int i = 0; i < v.size(); i++) {
		visited[i] = true;
		int left = 0;
		int right = 0;
		int sum = 0;
		for (int j = 0; j < v.size(); j++) { //여기서 한놈빼고 최대시간을 계산한다
			if (visited[j]) continue;
			else {
				if (left == 0) {
					sum += (v[j].second - v[j].first);
					left = v[j].first;
					right = v[j].second;
					continue;
				}
				else {
					if (right > v[j].second) {
						continue;
					}
					else if (v[j].first < right && right < v[j].second) {
						sum += (v[j].second - right);
						left = v[j].first;
						right = v[j].second;
					}
					else {
						sum+=(v[j].second - v[j].first);
						left = v[j].first;
						right = v[j].second;
					}
				}
			}
		}
		Max = max(Max, sum);
		visited[i] = false;
	}
	printf("%d\n", Max);
	return 0;
}