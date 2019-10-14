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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
struct position {
	
};
void go(int num,int here,int depth,vector<int> &v,int Plus,int Minus,int Multiply,int Divide,int &Maxans,int &Minans) {
	if (here == depth) {
		Maxans = max(Maxans, num);
		Minans = min(Minans, num);
		return;
	}
	if (Plus > 0) go(num + v[here], here + 1, depth, v, Plus - 1, Minus, Multiply, Divide, Maxans, Minans);
	if (Minus > 0) go(num - v[here], here + 1, depth, v, Plus, Minus-1, Multiply, Divide, Maxans, Minans);
	if (Multiply > 0) go(num * v[here], here + 1, depth, v, Plus, Minus, Multiply-1, Divide, Maxans, Minans);
	if (Divide > 0) go(num / v[here], here + 1, depth, v, Plus, Minus, Multiply, Divide-1, Maxans, Minans);
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v;
	int Plus, Minus, Multiply, Divide;
	int Minans = 1e9 + 5, Maxans = -1e9 - 5;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	scanf("%d%d%d%d", &Plus, &Minus, &Multiply, &Divide);
	go(v[0],1,n,v,Plus, Minus, Multiply, Divide,Maxans,Minans);
	printf("%d\n%d\n", Maxans, Minans);
	return 0;
}