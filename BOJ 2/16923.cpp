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
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
string s;
int visited[26];
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		visited[s[i] - 'a']++;
	}
	int sum = 0;
	for (int i = 0; i < 26; i++) {
		if (visited[i] >= 2) {
			printf("-1\n");
			return 0;
		}
		sum += visited[i];
	}
	if (sum == 26) {
		if (s == "zyxwvutsrqponmlkjihgfedcba") {
			printf("-1\n");
			return 0;
		}
		string v = s;
		next_permutation(s.begin(), s.end());
		string temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == v[i]) {
				temp.push_back(s[i]);
			}
			else {
				temp.push_back(s[i]);
				break;
			}
		}
		printf("%s\n", temp.c_str());
		
	}
	else {
		printf("%s", s.c_str());
		for (int i = 0; i < 26; i++) {
			int no = 0;
			for (int j = 0; j < s.size(); j++) {
				if (i + 'a' == s[j]) {
					no = 1;
					break;
				}
			}
			if (no) continue;
			else {
				printf("%c", i + 'a');
				break;
			}
		}
	}
	return 0;
}