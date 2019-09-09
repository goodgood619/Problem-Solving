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
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
char c[1000005];	
int n;
char check(char a, char b) {
	if (a > b) swap(a, b);
	if (a == b) return a;
	else {
		if (a == 'A' && b == 'G' || a=='G' && b=='A') return 'C';
		if (a == 'A' && b == 'C' || a=='C' && b=='A') return 'A';
		if (a == 'A' && b == 'T' || a=='T' && b=='A') return 'G';
		if (a == 'G' && b == 'C' || a=='C' && b=='G') return 'T';
		if (a == 'G' && b == 'T' || a=='T' && a=='G') return 'A';
		if (a == 'C' && b == 'T' || a=='T' && b=='C') return 'G';
	}
}
int main() {
	scanf("%d", &n);
	scanf("%s", c);
	int length = strlen(c);
	if (length == 1) {
		printf("%s", c);
		return 0;
	}
	char last = c[length - 1];
	for (int i = length - 2; i >= 0; i--) {
		char temp = check(c[i], last);
		last = temp;
	}
	printf("%c", last);
	return 0;
}