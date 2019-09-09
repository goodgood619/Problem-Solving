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
int gox[4] = { 0, 0,1,-1 };
int goy[4] = { 0, 1,1,1 };
int failure[1000005];
string s1, s2;
int main() {
	getline(cin, s1);
	getline(cin, s2);
	int j = 0;
	int length = s2.size();
	for (int i = 1; i < length; i++) {
		while (j > 0 && s2[i] != s2[j]) j = failure[j - 1];
		if (s2[i] == s2[j]) {
			failure[i] = j + 1;
			j++;
		}
	}
	j = 0;
	int idx = 0;
	int ans = 0;
	int length2 = s1.size();
	vector<int> v;
	for (int i = 0; i < length2; i++) {
		while (j > 0 && s1[i] != s2[j]) j = failure[j - 1];
		if (s1[i] == s2[j]) {
			if (j == length-1) {
				ans++;
				v.push_back(i - j+1);
				j = failure[j];
				continue;
			}
			j++;
		}
	}
	printf("%d\n",v.size());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	return 0;
}