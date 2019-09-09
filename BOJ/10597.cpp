#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
string s;
int total;
int cnt[10];
bool visited[55];
vector<int> v;
// 1자리 또는 2자리로 나눈다
// total값보다 커지면 유효하지가 않다
// 혹은 유효하다면 숫자를 집어넣는다
// 접근을 완전히 잘못한문제 ㅠㅠㅠ
// 그냥 1자리 2자리를 자른다고 생각했으면 편했을것!
void dfs(int index) {
	if (index == s.size()) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		exit(0);
		return;
	}
	string temp;
	for (int i = index; i <= index + 1; i++) {
		temp.push_back(s[i]);
		int num = stoi(temp);
		if (num > total || visited[num]) continue;
		visited[num] = true;
		v.push_back(num);
		dfs(index + temp.size());
		v.pop_back();
		visited[num] = false;
	}
}
int main() {
	cin >> s;

	if (s.size() < 10) {
		total = s.size();
	}
	else total = (s.size() - 9) / 2 + 9;
	dfs(0);
	return 0;
}