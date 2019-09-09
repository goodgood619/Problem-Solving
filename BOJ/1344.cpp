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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int a, b;
double dp[19][19][19];
int check(int num) { //소수면 리턴 1, 소수가 아니면 리턴 0
	if (num == 0 || num == 1) return 0;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0) return 0;
	}
	return 1;
}
double go(int index, int ascore, int bscore) {
	if (index == 18) {
		if (check(ascore) || check(bscore)) return 0; // 소수면 안되니까 불가능
		double d = 1,p=a,q=b;
		int anogoal = 18 - ascore,bnogoal=18-bscore;
		for (int i = 0; i < 18; i++) {
			if (anogoal == 0 && bnogoal == 0) {
				d *= (p / 100)*(q / 100);
			}
			else if (anogoal != 0 && bnogoal == 0) {
				d *= ((100 - p) / 100) * (q / 100);
				anogoal--;
			}
			else if (anogoal == 0 && bnogoal != 0) {
				d *= (p / 100)*((100 - q) / 100);
				bnogoal--;
			}
			else {
				d *= ((100 - p) / 100) * ((100 - q) / 100);
				anogoal--, bnogoal--;
			}
		}
		return d;
	}
	double &ret = dp[index][ascore][bscore];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			ret += go(index + 1, ascore + i, bscore + j);
		}
	}
	return ret;
}
int main(void) {
	scanf("%d%d", &a, &b);
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 18; j++) {
			for (int k = 0; k < 18; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	printf("%.6lf\n", 1 - go(0, 0, 0));
	return 0;
}