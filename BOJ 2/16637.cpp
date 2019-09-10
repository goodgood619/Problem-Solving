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
#define mod 1000000009
#define lim 1000000000
typedef pair <int, int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,-1,1,1,-1 };
int n,Max=-1e9-5;
string s;
bool visited[25];

void dfs(int index,int cnt,int depth) {
	if (cnt == depth) {
		queue<char> oper;
		deque<int> q;
		int num[25] = { 0, };
		int ptr = 1;
		bool check[25] = { false, };
		for (int i = 1; i < s.size(); i += 2) {
			if (visited[i]) {
				num[i - 1] = ptr,num[i+1]=ptr++;
			}
		}
		for (int i = 0; i < s.size();i+=2) {
			if (num[i] == 0 && num[i + 2] == 0) { // 둘다 괄호로 안묶였음
				q.push_back(s[i]-'0');
				if (i + 1 >= s.size()) continue;
				oper.push(s[i + 1]);
			}
			else if (num[i] == 0 && num[i + 2] != 0) { // 묶이지 않음
				q.push_back(s[i]-'0');
				if (i + 1 >= s.size()) continue;
				oper.push(s[i + 1]);
			}
			else if (num[i] != 0 && num[i + 2] != 0 && num[i]==num[i+2]) { //무조건 괄호로 묶임 그리고 괄호가 일치해야함
				int first = s[i] - '0', second = s[i + 2] - '0';
				if (s[i + 1] == '+') q.push_back(first+second);
				if (s[i + 1] == '-') q.push_back(first-second);
				if (s[i + 1] == '*') q.push_back(first*second);
			}
			else if (num[i] != 0 && num[i + 2] == 0 || num[i]!=0 && num[i+2]!=0) {// 괄호가 일치하지 않는 경우
				if (i + 1 >= s.size()) continue;
				oper.push(s[i + 1]);
			}
		}
		while (!oper.empty()) {
			int first = q.front();
			q.pop_front();
			int second = q.front();
			q.pop_front();
			char c = oper.front();
			oper.pop();
			if (c == '+') q.push_front(first + second);
			if (c == '-') q.push_front(first - second);
			if (c == '*') q.push_front(first*second);
		}
		Max = max(Max, q.front());
		return;
	}

	for (int i = index; i < s.size(); i += 2) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 4, cnt + 1, depth);
			visited[i] = false;
		}
	}
}
int main(void) {
	scanf("%d", &n);
	cin >> s;
	int depth = n / 2;
	depth /= 2;
	for (int i = 0; i <= depth; i++) {
		dfs(1,0,i);
	}
	printf("%d\n", Max);
	return 0;
}