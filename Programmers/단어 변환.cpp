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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
map<string, int> m;
map<int, string> match;
int dist[5000];
bool visited[5000];
int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	m[begin] = 1;
	match[1] = begin;
	int here = 2;
	for (int i = 0; i < words.size(); i++) {
		m[words[i]] = here;
		match[here] = words[i];
		here++;
	}
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		string s = match[here];
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			for (int j = 0; j < 26; j++) {
				s[i] += 1;
				if (s[i] > 'z') s[i] = 'a';
				if (m.count(s) != 0 && !visited[m[s]]) {
					visited[m[s]] = true;
					q.push(m[s]);
					dist[m[s]] = dist[here] + 1;
				}
			}
		}
	}
	if (dist[m[target]] == 0) answer = 0;
	else answer = dist[m[target]];
	return answer;
}