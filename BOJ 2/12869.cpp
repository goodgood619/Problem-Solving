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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n;
int arr[4];
int dp[65][65][65];
int go(int first,int second,int third) {
	if (first <= 0 && second <= 0 && third <= 0) return 0;
	if (first < 0) first = 0;
	if (second < 0) second = 0;
	if (third < 0) third = 0;
	int &ret = dp[first][second][third];
	if (ret != -1) return ret;
	ret = 1e9;

	if (first != 0 && second != 0 && third != 0) { //3마리 다살아있는경우
		vector<int> temp;
		temp.push_back(1),temp.push_back(3),temp.push_back(9);
		do {
			ret = min(ret, go(first - temp[0], second - temp[1], third - temp[2]) + 1);
		}while(next_permutation(temp.begin(), temp.end()));
	}
	if (first == 0 && second != 0 && third != 0) {
		vector<int> temp;
		temp.push_back(3), temp.push_back(9);
		do {
			ret = min(ret, go(0, second - temp[0], third - temp[1]) + 1);
		} while (next_permutation(temp.begin(), temp.end()));
	}
	if (first != 0 && second == 0 && third != 0) {
		vector<int> temp;
		temp.push_back(3), temp.push_back(9);
		do {
			ret = min(ret, go(first-temp[0], 0, third - temp[1]) + 1);
		} while (next_permutation(temp.begin(), temp.end()));
	}
	if (first != 0 && second != 0 && third == 0) {
		vector<int> temp;
		temp.push_back(3), temp.push_back(9);
		do {
			ret = min(ret, go(first-temp[0], second - temp[1],0) + 1);
		} while (next_permutation(temp.begin(), temp.end()));
	}
	if (first == 0 && second == 0 && third != 0) {
		vector<int> temp;
		temp.push_back(9);
		ret = min(ret, go(0, 0, third - 9) + 1);
	}
	if (first == 0 && second != 0 && third == 0) {
		vector<int> temp;
		temp.push_back(9);
		ret = min(ret, go(0, second-9,0) + 1);
	}
	if (first != 0 && second == 0 && third == 0) {
		vector<int> temp;
		temp.push_back(9);
		ret = min(ret, go(first-9, 0,0) + 1);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",go(arr[1], arr[2], arr[3]));
	return 0;
}