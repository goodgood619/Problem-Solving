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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int n;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<int> v;
vector<double> vv;
int Max = 0;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
		Max = max(Max, num);
	}
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		int num;
		double d = (double)v[i] / (double)Max;
		sum += d;
	}
	printf("%.2lf\n", (double)sum / v.size()*100);
	return 0;
}