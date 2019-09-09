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
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
string s[100];
int board[30][30];
int n;
map<char, int> m;
map<string, int> check;
bool compare(const P &a, const P &b) {
	if (a.first != b.first) return a.first > b.first;
}
// s[i-x]의 길이가 s[i]의길이보다 큰경우
// 혹시, s[i]가 s[i-x]에 완전히 속해있으면 !출력
int main() {
	scanf("%d", &n);
	int length = 0;
	int cnt[26] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		int l = s[i].size();
		for (int j = 0; j < l; j++) {
			if (m.count(s[i][j]) == 0) {
				m[s[i][j]] = 1;
			}
		}
		check[s[i]]++;
		length = max(length, l);
	}
	map<string, int>::iterator it;
	int Max = 0;
	for (it = check.begin(); it != check.end(); it++) {
		Max = max(Max, it->second);
	}
	if (Max == n && s[0].size() == 1) {
		printf("%s\n", s[0].c_str());
		return 0;
	}
	for (int j = 0; j < length; j++) {
		for (int i = 0; i < n - 1; i++) {
			for (int k = i + 1; k < n; k++) {
				int heresize = s[i].size();
				int nextsize = s[k].size();
				if (heresize <= j || nextsize <= j) continue; // 둘중에 하나라도 범위를 벗어나는 경우
				if (heresize > nextsize) {
					string up, down;
					for (int p = 0; p < heresize; p++) {
						up.push_back(s[i][p]);
					}
					for (int r = 0; r < nextsize; r++) {
						down.push_back(s[k][r]);
					}
					int same = 0;
					for (int p = 0; p < nextsize; p++) {
						if (up[p] == down[p]) same++;
					}
					if (same == nextsize) {
						printf("!\n");
						return 0;
					}
				}
				if (j == 0) {
					char here = s[i][j];
					char next = s[k][j];
					if (here == next) continue;
					else {
						int p = board[here - 'a'][next - 'a'];
						board[here - 'a'][next - 'a'] = 1;
						board[next - 'a'][here - 'a'] = -1;
						if (p != board[here - 'a'][next - 'a'] && p!=0) {
							printf("!\n");
							return 0;
						}
					}
				}
				else { // 앞의 단어의 순서를따진다. 일치해야함
					string up, down;
					if (heresize <= j || nextsize <= j) continue;
					for (int p = 0; p < j; p++) {
						up.push_back(s[i][p]);
						down.push_back(s[k][p]);
					}
					if (up != down) continue;
					else {
						int p = board[s[i][j] - 'a'][s[k][j] - 'a'];
						if (s[i][j] == s[k][j]) continue;
						board[s[i][j] - 'a'][s[k][j] - 'a'] = 1;
						board[s[k][j] - 'a'][s[i][j] - 'a'] = -1;
						if (p != board[s[i][j] - 'a'][s[k][j] - 'a'] && p!=0) {
							printf("!\n");
							return 0;
						}
					}
				}
			}
		}
	}
	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				if (board[i][k] == 0 || board[k][j] == 0) continue;
				if (board[i][k] == 1 && board[k][j] == 1) board[i][j] = 1;
				if (board[i][k] == -1 && board[k][j] == -1) board[i][j] = -1;
			}
		}
	}
	vector<pair<int, int>> v;
	for (int i = 0; i < 26; i++) {
		int win = 0;
		int lose = 0;
		for (int j = 0; j < 26; j++) {
			if (board[i][j] == 1) win++;
			if (board[i][j] == -1) lose++;
		}
		if (win > 0) v.push_back({ win,i });
		if (lose == m.size() - 1) v.push_back({ 0,i });
	}
	if (Max == n) {
		printf("?\n");
		return 0;
	}
	Max = 0;
	int same = 0;
	for (int i = 0; i < v.size(); i++) {
		Max = max(Max, v[i].first);
		cnt[v[i].first]++;
		same = max(same, cnt[v[i].first]);
	}
		if (Max > v.size() && v.size()<m.size()) printf("!\n");
		else if (Max < v.size() && same >= 2 && v.size()<m.size()) printf("!\n");
		else if (v.size()==m.size() && same>=2) printf("?\n");
		else if (v.size() < m.size() && same == 1) printf("?\n");
		else {
			sort(v.begin(), v.end(), compare);
			for (int i = 0; i < v.size(); i++) {
				printf("%c", v[i].second + 'a');
			}
		}
	return 0;
}