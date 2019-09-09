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
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
string s;
int main() {
	cin >> s;
	int idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') {
			idx = i;
			break;
		}
	}
	if (idx != 0) {
		for (int i = idx; i < s.size(); i++) {
			if (s[i] == '+') {
				s[i] = '-';
			}
		}
		string temp;
		int sum = 0;
		for (int i = 0; i < idx; i++) {
			if (s[i] == '+') {
				sum += stoi(temp);
				temp.clear();
			}
			else temp.push_back(s[i]);
		}
		if (!temp.empty()) sum += stoi(temp);
		temp.clear();
		for (int i = idx; i < s.size(); i++) {
			if (s[i] == '-') {
				if (temp.empty()) continue;
				sum -= stoi(temp);
				temp.clear();
			}
			else temp.push_back(s[i]);
		}
		if (!temp.empty()) sum -= stoi(temp);
		printf("%d\n", sum);
	}
	else {
		string temp;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+') {
				sum += stoi(temp);
				temp.clear();
			}
			else temp.push_back(s[i]);
		}
		if (!temp.empty()) sum += stoi(temp);
		printf("%d\n", sum);
	}
	return 0;
}