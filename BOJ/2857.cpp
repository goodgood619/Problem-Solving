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
	vector<string> v;
	for (int i = 0; i < 5; i++) {
		string temp;
		cin >>temp;
		v.push_back(temp);
	}
	s2 = "FBI";
	int j = 0;
	int length = s2.size();
	for (int i = 1; i < length; i++) {
		while (j > 0 && s2[i] != s2[j]) j = failure[j - 1];
		if (s2[i] == s2[j]) {
			failure[i] = j + 1;
			j++;
		}
	}
	vector<int> t;
	for (int i = 0; i < v.size(); i++) {
		j = 0;
		int idx = 0;
		int ans = 0;
		s1 = v[i];
		for (int k = 0; k <s1.size(); k++) {
			while (j > 0 && s1[k] != s2[j]) j = failure[j - 1];
			if (s1[k] == s2[j]) {
				if (j == length - 1) {
					ans++;
					t.push_back(i+1);
					j = failure[j];
					continue;
				}
				j++;
			}
		}
	}
	if (t.size() == 0) {
		printf("HE GOT AWAY!\n");
		return 0;
	}
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	for (int i = 0; i < t.size(); i++) {
		printf("%d ", t[i]);
	}
	return 0;
}