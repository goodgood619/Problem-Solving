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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n, ans,length;
char s[5][20],t;
string a;
map<char, int> m;
bool visited[11];
int v[26];
int check[26];
void dfs(int index, int cnt, int depth) {
	if (cnt == depth) {
		int sum = 0,total=0;
		for (int i = 0; i <2; i++) {
			int length = strlen(s[i]),temp=0;
			for (int j = 0; j<length; j++) {
				temp *= 10;
				temp += v[s[i][j] - 'A'];
			}
			sum += temp;
		}
		int length = strlen(s[2]);
		for (int j = 0; j <length; j++) {
			total *= 10;
			total += v[s[2][j] - 'A'];
		}
		if (sum == total) {
			printf("YES\n");
			exit(0);
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
			if (!visited[i]) {
				visited[i] = true;
				v[a[index] - 'A'] = i;
				dfs(index + 1, cnt + 1, depth);
				v[a[index] - 'A'] = 0;
				visited[i] = false;
			}
	}
}
int main() {
	for (int i = 0; i <3; i++) {
		scanf("%s", s[i]);
		int temp = strlen(s[i]);
		length = max(length, temp);
	}
	for (int i = 0; i < 3; i++) {
		int temp = strlen(s[i]);
		for (int j = 0; j < temp; j++) {
			if (m.count(s[i][j]) == 0) {
				m[s[i][j]] = 1;
				a.push_back(s[i][j]);
			}
		}
	}
	dfs(0, 0, m.size());
	printf("NO\n");
	return 0;
}