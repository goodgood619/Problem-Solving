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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int arr2[500005];
P temp[500005];
int n;
P arr[500005];
map<int, int> m; // 원래 등수
map<int, int> mm;
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first != b.first) return a.first < b.first;
}
void merge(P arr[], int left, int mid, int right) {
	int lleft = left;
	int lright = mid;
	int rleft = mid + 1;
	int rright = right;
	int idx = left;
	// 왼쪽블록 lleft~lright 오른쪽블록 rleft~rright
	while (lleft <= lright && rleft <= rright) {
		if (arr[lleft].first < arr[rleft].first) { //오른쪽이 더 크니까 남은 왼쪽의 블록갯수에서 갱신한다
			temp[idx].first = arr[rleft].first;
			temp[idx].second = arr[rleft].second -(lright-lleft+1);
			//m[arr[rleft]] -= (lright - lleft+1);
			idx++;
			rleft++;
		}
		else {
			temp[idx].first = arr[lleft].first;
			temp[idx].second = arr[lleft].second;
			lleft++,idx++;
		}
	}
	while (rleft <= rright) {
		temp[idx].first = arr[rleft].first;
		temp[idx].second = arr[rleft].second;
		idx++,rleft++;
	}
	while (lleft <= lright) {
		temp[idx].first = arr[lleft].first;
		temp[idx].second = arr[lleft].second;
		idx++, lleft++;
	}
	for (int i = left; i <=right; i++) {
		arr[i] = temp[i];
	}
}
void go(P arr[], int left, int right) {
	int mid = (left + right) / 2;
	if(left<right)
	{
		go(arr, left, mid);
		go(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
int main() {
	scanf("%d", &n);
	// map으로 하면 터지니까,원래 순서의 index -> 원래순서의 실력, 바뀌는 등수
	for (int i = 1; i <= n; i++) {
		int num;
		scanf(" %d", &num);
		arr[i] = { num,i };
		arr2[i] = num;
	}

	go(arr, 1, n);
	vector<P> v;
	for (int i = 1; i <= n; i++) {
		v.push_back({ arr[i].first,arr[i].second });
	}
	sort(v.begin(), v.end(), compare);
	vector<P>::iterator it;
	for (int i = 1; i <= n; i++) {
		auto it=lower_bound(v.begin(),v.end(),P(arr2[i],1));
		printf("%d\n", it->second);
	}

	return 0;
}