#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string s1,s2;
int n;
typedef long long ll;
string ans[10005];
string bigadd(string s1, string s2) {
	ll sum = 0;
	string temp;
	while (!s1.empty() || !s2.empty() || sum) {
		if (!s1.empty()) {
			sum += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty()) {
			sum += s2.back() - '0';
			s2.pop_back();
		}
		temp.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
int main(){
	cin >> n;
	ans[0] = "0";
	ans[1] = "1";
	for (int i = 2; i <=n; i++) {
		ans[i]=bigadd(ans[i - 1], ans[i - 2]);
	}
	cout << ans[n] << endl;
	return 0;
}