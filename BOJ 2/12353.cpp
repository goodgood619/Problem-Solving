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
typedef pair<int, int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<ll, pair<ll, ll >> PPP;
typedef pair<pair<ll, ll>, pair<ll, ll>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
int main() {
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		char c;
		int fatfeet = 0, fatinch = 0, momfeet = 0, mominch = 0;
		scanf(" %c", &c);
		string dad, mom;
		cin >> dad >> mom;
		if (dad[3] >= '0' && dad[3] <= '1') {
			fatfeet = dad[0] - '0';
			fatinch = 10 * (dad[2] - '0') + dad[3] - '0';
		}
		else {
			fatfeet = dad[0] - '0';
			fatinch = dad[2] - '0';
		}
		if (mom[3] >= '0' && mom[3] <= '1') {
			momfeet = mom[0] - '0';
			mominch = 10 * (mom[2] - '0') + mom[3] - '0';
		}
		else {
			momfeet = mom[0] - '0';
			mominch = mom[2] - '0';
		}

		double totalinch = (fatfeet + momfeet) * 12 + fatinch + mominch;
		if (c == 'B') totalinch += 5;
		else totalinch -= 5;
		totalinch /= 2;
		double lowinch = totalinch - 4, highinch = totalinch + 4;
		if (totalinch - (int)totalinch != 0) {
			lowinch += 0.5, highinch -= 0.5;
			printf("Case #%d: %d\'%d\" to %d\'%d\"\n", Case, (int)(lowinch) / 12, (int)(lowinch) % 12, (int)(highinch) / 12, (int)(highinch ) % 12);
			Case++;
		}
		else {
			printf("Case #%d: %d\'%d\" to %d\'%d\"\n", Case, (int)(lowinch) / 12, (int)(lowinch) % 12, (int)(highinch) / 12, (int)(highinch) % 12);
			Case++;
		}

	}
	return 0;
}