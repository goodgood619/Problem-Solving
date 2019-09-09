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
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int main() {
	scanf("%d", &n);
	string s1 = "ABCDEFGHIJKL";
	string s2 = "0123456789";
	int idx1 = 8;
	int idx2 = 6;
	vector<string> v;
	v.resize(65);
	// K8: 2년
	// L9: 3년
	// A0: 4년
	for (int i = 0; i <60; i++) {
		string temp;
		temp.push_back(s1[idx1]);
		temp.push_back(s2[idx2]);
		v[i] = temp;
		idx1++;
		idx2++;
		if (idx1 == s1.size()) idx1 = 0;
		if (idx2 == s2.size()) idx2 = 0;
	}
	printf("%s\n", v[n%60].c_str());
	return 0;
}