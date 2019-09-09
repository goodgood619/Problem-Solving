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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n;
string s;
int check(int num) {
	if (num == 0 || num == 1) return true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) return true;
	}
	return false;
}
void go(int cnt) {
	if (cnt == n) {
		if (check(stoi(s))) return;
		printf("%s\n", s.c_str());
		return;
	}
	if (s.size()>=1 && check(stoi(s))) return;
	for (int i = 0; i < 10; i++) {
		s.push_back(i + '0');
		go(cnt + 1);
		s.pop_back();
	}
}
int main() {
	scanf("%d", &n);
	go(0);
	return 0;
}