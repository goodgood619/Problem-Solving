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
int a[10002];
int n;
void f(int st, int ed)
{
	if (st>ed) return;
	int left = st;
	int right = ed;
	while (a[left] >= a[st]) left++; // a[st]보다 바로 작아지는 위치찾기
	while (a[right] > a[st]) right--;
	f(left, right);
	f(right+1, ed);
	printf("%d\n", a[st]);
}

int main() {
	while (scanf("%d", &a[n]) != EOF)
		n++;

	f(0, n - 1);
	return 0;
}