#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;
string s;
int main() {
	cin >> s;
	int length = s.size();
	ll sum = 0;
	vector<ll> temp;
	temp.push_back(1);
	for (int i = 1; i <= length; i++) {
		temp.push_back(pow(10, i-1));
	}
	for (int i = 0; i < length; i++) {
		sum += (s[i] - '0')*pow(10, length - i - 1);
	}
	ll cnt = 0;
	for (int i = 1; i <= length - 1; i++) {
		cnt += ((9 * pow(10, i - 1))*i);
	}
	cnt += ((sum - temp[length]+1)*length);
	printf("%lld\n", cnt);
	return 0;
}