#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
string dp[105][105];
int n, m;
typedef long long ll;
string bigadd(string s1, string s2) {
	ll sum = 0;
	string temp;
	while (!s1.empty() || !s2.empty() || sum!=0){
		if (!s1.empty()) {
			sum+=s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty()){
			sum += s2.back() - '0';
			s2.pop_back();
		}
		temp.push_back(sum % 10+'0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
string go(int n, int m) {
	if (n == m || m == 0) return "1";
	string &ret = dp[n][m];
	if (ret != "") return ret;
	ret=bigadd(go(n - 1, m) ,go(n - 1, m - 1));
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	cout << go(n, m) << endl;
	return 0;
}