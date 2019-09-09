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
int board[105][105];
char a[10], b[10],c[10],d[10];
int main() {
	scanf("%s%s", a, b);
	int length = strlen(a);
	int length2 = strlen(b);
	strcpy(c, a);
	strcpy(d, b);
	for (int i = 0; i < length; i++) {
		if (a[i] == '5') c[i] = '6';
	}
	for (int i = 0; i < length2; i++) {
		if (b[i] == '5') d[i] = '6';
	}
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += (c[i] - '0')*pow(10, length - i - 1);
	}
	for (int i = 0; i < length2; i++) {
		sum += (d[i] - '0')*pow(10, length2 - i - 1);
	}
	int Max = sum;
	strcpy(c, a);
	strcpy(d, b);
	for (int i = 0; i < length; i++) {
		if (a[i] == '6') c[i] = '5';
	}
	for (int i = 0; i < length2; i++) {
		if (b[i] == '6') d[i] = '5';
	}
	int sum2 = 0;
	for (int i = 0; i < length; i++) {
		sum2 += (c[i] - '0')*pow(10, length - i - 1);
	}
	for (int i = 0; i < length2; i++) {
		sum2 += (d[i] - '0')*pow(10, length2 - i - 1);
	}
	printf("%d %d", sum2, Max);
	return 0;
}