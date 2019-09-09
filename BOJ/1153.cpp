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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int isprime[1000005];
vector<int> v;
int main() {
	for (int i = 2; i <= 1000000; i++) isprime[i] = i;
	for (int i = 2; i <= sqrt(1000000); i++) {
		if (isprime[i] == 0) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			isprime[j] = 0;
		}
	}
	int n;
	scanf("%d", &n);
	if (n < 8) {
		printf("-1\n");
		return 0;
	}
	if (n % 2 == 0) {
		v.push_back(2);
		v.push_back(2);
		n -= 4;
		for (int i = 2; i <= 1000000; i++) {
			if (isprime[i] == 0) continue;
			else {
				if (isprime[n-i]!=0 && n>i) {
					v.push_back(n-i);
					v.push_back(i);
					break;
				}
			}
		}
		if (v.size() != 4) printf("-1\n");
		else {
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
		}
	}
	else {
		v.push_back(2);
		v.push_back(3);
		n -= 5;
		for (int i = 2; i <= 1000000; i++) {
			if (isprime[i] == 0) continue;
			else {
				if (isprime[n-i]!=0 &&n>i) {
					v.push_back(n-i);
					v.push_back(i);
					break;
				}
			}
		}
		if (v.size() != 4) printf("-1\n");
		else {
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
		}
	}
	return 0;
}