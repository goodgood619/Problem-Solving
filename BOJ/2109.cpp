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
#include <math.h>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;
int n;
typedef pair<int, int> P;
vector<P> arr;
priority_queue<int, vector<int>> pq;
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int cost, day;
		scanf("%d%d", &cost, &day);
		arr.push_back({ day,cost });
	}
	sort(arr.begin(), arr.end());
	int length = arr.size();
	ll sum = 0;
	int Maxday =0;
	for (int i = 0; i < length; i++){
		int day = arr[i].first;
		sum += (ll)arr[i].second;
		pq.push(-arr[i].second);
		if (pq.size() > day) {
			sum += (ll)pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", sum);
	return 0;
}