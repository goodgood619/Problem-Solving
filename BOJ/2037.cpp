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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int p, w;
string s;
string num[8] = { "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ" };
int count(char c) {
	int ok2 = 0,cnt = 0;
	for (int j = 0; j < 8; j++) {
		for (int k = 0; k < num[j].size(); k++) {
			if (c == num[j][k]) {
				ok2 = 1;
				cnt = k + 1;
				break;
			}
		}
		if (ok2) break;
	}
	return cnt;
}
int main() {
	scanf(" %d %d ", &p, &w);
	getline(cin, s);
	char c = s[0];
	int total = 0;
	if (c == ' ') total = p;
	else {
		int cnt = count(s[0]);
		total += p * cnt;
	}
	for (int i = 1; i < s.size(); i++) { //c:이전문자, s[i]:현재문자
		if (c == ' ' && s[i] == ' ') { //연속공백
			total += p;
		}
		else if (c == ' ' && s[i] != ' ') { //연속공백아님(대기시간없음)
			c = s[i];
			int ok2 = 0, next = 0;
			int cnt = count(s[i]);
			total += cnt * p;
		}
		else if (c != ' ' && s[i] == ' ') { //다음이 공백인 경우
			c = s[i];
			total += p;
		}
		else if (c != ' ' && s[i] != ' ') { // 둘다 문자인경우(연속적인 버튼인지 아닌지를 확인해야함) 
			int cur = 0, next = 0;
			int ok = 0, ok2 = 0, cnt = 0;

			for (int j = 0; j < 8; j++) { //이전번호가 어디인지 파악
				for (int k = 0; k < num[j].size(); k++) {
					if (c == num[j][k]) {
						cur = j;
						ok = 1;
						break;
					}
				}
				if (ok) break;
			}

			for (int j = 0; j < 8; j++) { //현재번호가 어디있는지 파악
				for (int k = 0; k < num[j].size(); k++) {
					if (s[i] == num[j][k]) {
						ok2 = 1;
						next = j;
						cnt = k + 1;
						break;
					}
				}
				if (ok2) break;
			}
			if (cur == next) { // 같은 번호위에있다면
				total += w;
				total += cnt * p;
				c = s[i];
			}
			else { // 다른번호위에있다면
				total += cnt * p;
				c = s[i];
			}
		}
	}
	printf("%d\n", total);
	return 0;
}