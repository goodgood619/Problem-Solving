#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
string s1,s2;
typedef long long ll;
string bigadd(string s1, string s2){
	ll sum = 0;
	string temp;
	while (!s1.empty() || !s2.empty() || sum) {
		if (!s1.empty()) {
			sum += s1.back()-'0';
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
	cin >> s1;
	cin >> s2;
	cout << bigadd(s1, s2) << endl;
	return 0;
}