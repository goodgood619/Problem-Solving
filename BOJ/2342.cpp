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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int arr[100005];
int dp[100005][6][6];
int go(int index, int left, int right) {
	if (index >= n) return 0;
	int &ret = dp[index][left][right];
	if (ret != -1) return ret;
	ret = 1e9;

	if (left == 0 && right == 0) {
		ret = min(ret, go(index + 1, arr[index + 1], right) + 2);
		ret = min(ret, go(index + 1, left, arr[index + 1]) + 2);
	}
	if (left == arr[index + 1] && right != arr[index + 1]) {
		ret = min(ret, go(index + 1, left, right) + 1);
	}
	if (left != arr[index + 1] && right == arr[index + 1]) {
		ret = min(ret, go(index + 1, left, right) + 1);
	}
	if (left != arr[index + 1] && right != arr[index + 1]) {
		int ldiff = 0, rdiff = 0;
		if (left == 2 || left == 4) {
			if (arr[index + 1] == 1 || arr[index + 1] == 3) ldiff = 3;
			else if(arr[index+1]==2 || arr[index+1]==4) ldiff = 4;
		}
		else if(left==1 || left==3){
			if (arr[index + 1] == 2 || arr[index + 1] == 4) ldiff = 3;
			else ldiff = 4;
		}
		else {
			ldiff = 2;
		}
		if (right == 2 || right == 4) {
			if (arr[index + 1] == 1 || arr[index + 1] == 3) rdiff = 3;
			else rdiff = 4;
		}
		else if(right==1 || right==3){
			if (arr[index + 1] == 2 || arr[index + 1] == 4) rdiff = 3;
			else rdiff = 4;
		}
		else rdiff = 2;
		ret = min(ret, min(go(index + 1, arr[index + 1], right) + ldiff, go(index + 1, left, arr[index + 1])+ rdiff));
	}
	return ret;
}
int main() {
	int p = 1;
	while (1) {
		int num;
		scanf("%d", &num);
		if (num == 0) break;
		arr[p++] = num;
		n = p;
	}
	n--;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0, 0));
	return 0;
}