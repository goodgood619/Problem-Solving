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
typedef pair<pair<int, int>, pair<int, char>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
vector<int> a, b;
int ok[2001];
void fday(int milk, vector<int> a, vector<int> b) {
	for (int i = 0; i < b.size(); i++) {
		int x = b[i];
		ok[milk + x] = 1;
	}
}
void t2day(int milk, vector<int> a, vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		int x = a[i];
		vector<int> copyb = b;
		copyb.push_back(x);
		vector<int> copya = a;
		copya.erase(copya.begin() + i);
		fday(milk - x, copya, copyb);
	}
}
void wday(int milk, vector<int> a, vector<int> b) {
	for (int i = 0; i < b.size(); i++) {
		int x = b[i];
		vector<int> copya = a;
		copya.push_back(x);
		vector<int> copyb = b;
		copyb.erase(copyb.begin() + i);
		t2day(milk + x, copya, copyb);
	}
}
void tday(int milk,vector<int> a,vector<int> b) {
	for (int i = 0; i < a.size(); i++) {
		int x = a[i];
		vector<int> copyb = b;
		copyb.push_back(x);
		vector<int> copya = a;
		copya.erase(copya.begin() + i);
		wday(milk - x, copya, copyb);
	}
}
int main() {
	for (int i = 1; i <= 10; i++) {
		int num;
		scanf("%d", &num);
		a.push_back(num);
	}
	for (int i = 1; i <= 10; i++)
	{
		int num;
		scanf("%d", &num);
		b.push_back(num);
	}
	int ans = 0;
	tday(1000, a, b);
	for (int i = 0; i <= 2000; i++) {
		if (ok[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}