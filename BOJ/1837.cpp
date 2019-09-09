
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
string p;
int k;
bool check[1000005];
int main() {
	vector<int> v;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (check[i]) continue;
		for (int j = i*i; j <= 1000000; j += i) {
			check[j] = true;
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (!check[i]) v.push_back(i);
	}

	cin >> p >> k;

	for (int i = 0; i < v.size() && v[i]<k; i++) {
		int ret = 0;
		for (int j = 0; j < p.size(); j++) {
			ret = (ret * 10 + (p[j] - '0')) % v[i]; //엄청 큰수를 특정한 수로 나눈 나머지를 구하고싶을때
		}
		if (ret==0) {
			printf("BAD %d \n", v[i]);
			return 0;
		}
	}
	printf("GOOD\n");
	return 0;
}