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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n;
int change[4][101],milk[4][101];
bool MAX(int i, int j) {
	int high = max({ milk[1][j],milk[2][j],milk[3][j] });
	if (high == milk[i][j]) return true;
	else return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int day, milks;
		string name;
		cin >> day >> name >> milks;
		int temp = 0;
		if (name == "Bessie") temp = 1;
		if (name == "Elsie") temp = 2;
		if (name == "Mildred") temp = 3;
		change[temp][day] = milks;
	}
	for (int i = 1; i <= 3; i++) milk[i][0] = 7;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 100; j++) {
			milk[i][j] = milk[i][j - 1] + change[i][j];
		}
	}
	int days = 0;
	for (int i = 1; i <= 100; i++) {
		if (MAX(1, i - 1) != MAX(1, i) || MAX(2, i - 1) != MAX(2, i) || MAX(3, i - 1) != MAX(3, i)) days++;
	}
	printf("%d\n", days);
	return 0;
}