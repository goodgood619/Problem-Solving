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
int failure[5005];
string s1;
int main() {
	getline(cin, s1);
	vector<string> v;
	v.push_back(s1);
	while (!s1.empty()) {
		s1.erase(s1.begin());
		v.push_back(s1);
	}
	int Max = 0;
	for (int k = 0; k < v.size(); k++) {
		int j = 0;
		string s = v[k];
		memset(failure, 0, sizeof(failure));
		for (int i =1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j]) j = failure[j - 1];
			if (s[i] == s[j]) {
				failure[i] = j+1;
				Max = max(Max, failure[i]);
				j++;
			}
		}
	}
	printf("%d\n", Max);
	return 0;
}