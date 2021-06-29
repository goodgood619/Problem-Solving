#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
bool testString(string& s) {
	int frontSum = 0, backSum = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		frontSum += (s[i]-'0');
	}
	for (int i = s.size() / 2; i < s.size(); i++) {
		backSum += (s[i] - '0');
	}
	if (frontSum == backSum) return true;
	else return false;
}
int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		int addIndex = 2;
		for (int j = 2; j <= s.size(); j += addIndex) {
			string subString = s.substr(i, j);
			if (testString(subString) && subString.size() % 2 == 0) {
				ans = max(ans, (int) subString.size());
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}