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
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		string check = to_string(n);
		int flag = 1;
		ll sum = 0;
		if (check[0]>='5') {
			for (ll i = 1; i <= n;) {
				if (flag) {
					string temp = to_string(i);
					string temp2;
					for (int j = 0; j < temp.size(); j++) {
						temp2.push_back('9' - temp[j] + '0');
					}
					sum = max(sum, i*stoll(temp2));
					flag = 0;
					i *= 5;
				}
				else {
					string temp = to_string(i);
					string temp2;
					for (int j = 0; j < temp.size(); j++) {
						temp2.push_back('9' - temp[j] + '0');
					}
					sum = max(sum, i*stoll(temp2));
					flag = 1;
					i *= 2;
				}
			}
			printf("%lld\n", sum);
		}
		else {
			string temp = to_string(n);
			string temp2;
			for (int j = 0; j < temp.size(); j++) {
				temp2.push_back('9' - temp[j] + '0');
			}
			printf("%lld\n", n*stoll(temp2));
		}
	}
	return 0;
}