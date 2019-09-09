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
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
bool check[10000003];
map<int, int> m;
int t,n,ans;
string s,v;
bool visited[10];
void go(int index,int cnt,int depth) {
	if (cnt == depth) {
		string temp=v;
		sort(temp.begin(), temp.end());
		do {
			int num = stoi(temp);
			if (!check[num] && m.count(num) == 0) {
				m[stoi(temp)] = 1;
				ans++;
			}
		} while (next_permutation(temp.begin(), temp.end()));
		return;
	}

	for (int i = index; i < s.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(s[i]);
			go(i + 1, cnt + 1, depth);
			v.pop_back();
			visited[i] = false;
		}
	}

}
int main() {
	check[0] = true, check[1] = true;
	for (int i = 2; i <= sqrt(10000000); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			check[j] = true;
		}
	}
	scanf("%d", &t);
	while (t--) {
		cin >> s;
		int length = s.size();
		n = stoi(s);
		m.clear();
		ans = 0;
		//sort(s.begin(), s.end());
		for (int i = 1; i <= length; i++) {
			go(0,0,i);
		}
		printf("%d\n", ans);
	}
	return 0;
}