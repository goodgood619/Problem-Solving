
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
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n1, m1, s1, n2, m2, s2;
int main() {
	scanf("%d:%d:%d", &n1, &s1, &m1);
	scanf("%d:%d:%d", &n2, &s2, &m2);
	if (n2 < n1) {
		n2 += 24;
		n2 -= n1;
		if (m2 < m1) {
			m2 += 60;
			s2 -= 1;
			m2 -= m1;
		}
		else {
			m2 -= m1;
		}
		if (s2 < s1) {
			s2 += 60;
			n2 -= 1;
			s2 -= s1;
		}
		else s2 -= s1;
		if (n2 == 0 && m2 == 0 && s2 == 0) printf("24:00:00\n");
		else if (n2 < 10 && s2 < 10 && m2 < 10) printf("0%d:0%d:0%d\n", n2, s2, m2);
		else if (n2 < 10 && s2 > 10 && m2 < 10) printf("0%d:%d:0%d\n", n2, s2, m2);
		else if (n2 < 10 && s2 > 10 && m2 > 10) printf("0%d:%d:%d\n", n2, s2, m2);
		else if (n2 < 10 && s2 < 10 && m2>10) printf("0%d:0%d:%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 < 10 && m2 < 10) printf("%d:0%d:0%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 > 10 && m2 < 10) printf("%d:%d:0%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 > 10 && m2 > 10) printf("%d:%d:%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 < 10 && m2>10) printf("%d:0%d:%d\n", n2, s2, m2);
	}
	else if (n2>= n1) {
		n2 -= n1;
		if (m2 < m1) {
			m2 += 60;
			s2 -= 1;
			m2 -= m1;
		}
		else {
			m2 -= m1;
		}
		if (s2 < s1) {
			s2 += 60;
			n2 -= 1;
			s2 -= s1;
		}
		else s2 -= s1;
		if (n2 == 0 && m2 == 0 && s2 == 0) printf("24:00:00\n");
		else if (n2 < 10 && s2 < 10 && m2 < 10) printf("0%d:0%d:0%d\n", n2, s2, m2);
		else if (n2 < 10 && s2 > 10 && m2 < 10) printf("0%d:%d:0%d\n", n2, s2, m2);
		else if (n2 < 10 && s2 > 10 && m2 > 10) printf("0%d:%d:%d\n", n2, s2, m2);
		else if (n2 < 10 && s2 < 10 && m2>10) printf("0%d:0%d:%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 < 10 && m2 < 10) printf("%d:0%d:0%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 > 10 && m2 < 10) printf("%d:%d:0%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 > 10 && m2 > 10) printf("%d:%d:%d\n", n2, s2, m2);
		else if (n2 > 10 && s2 < 10 && m2>10) printf("%d:0%d:%d\n", n2, s2, m2);
	}
	return 0;
}

