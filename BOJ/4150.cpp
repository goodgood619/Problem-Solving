#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int a;
string dp[1000005];
string bigadd(string s1,string s2){
	string temp;
	int sum = 0;
	while (!s1.empty() || !s2.empty() || sum) {
		if (!s1.empty()) {
			sum += (s1.back() - '0');
			s1.pop_back();
		}
		if (!s2.empty()) {
			sum += (s2.back() - '0');
			s2.pop_back();
		}
		temp.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
string go(int n){
	if (n == 0) return "0";
	if (n == 1) return "1";
	string &ret = dp[n];
	if (ret != "") return ret;
	ret = bigadd(go(n - 1),go(n-2));
	return ret;
}
int main(){
	scanf("%d", &a);
	if (a == 1) printf("1\n");
	else if (a == 2) printf("1\n");
	else {
		printf("%s\n", go(a).c_str());
	}
	return 0;
}