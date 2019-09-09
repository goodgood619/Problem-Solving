#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int a, b;
vector<int> v;
int go(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= 9; i++)v.push_back(i);
	for (int i = 1; i <10000; i++){
		string s;
		string rs;
		string hal;
		int p = i;
		while (p > 0){
			s.push_back(p % 10 + '0');
			rs.push_back(p % 10 + '0');
			p /= 10;
		}
		reverse(s.begin(),s.end());
		hal = s;
		s.append(rs.begin(), rs.end());
		
		//짝수
		int num = 0;
		for (int i = 0; i < s.size(); i++) {
			num += (s[i] - '0')*pow(10, s.size() - 1 - i);
		}
		v.push_back(num);
		for (int i = 0; i < 10; i++) {
			string temp;
			char c = i+'0';
			hal.push_back(c);
			temp = hal;
			temp.append(rs.begin(), rs.end());
			int num = 0;
			for (int j = 0; j< temp.size(); j++){
				num += (temp[j] - '0')*pow(10, temp.size() - 1 - j);
			}
			v.push_back(num);
			hal.pop_back();
		}
	}
	vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		if (v[i]<a || v[i]>b) continue;
		else {
			int check=go(v[i]);
			if (check) ans.push_back(v[i]);
		}
	}
	ans.push_back(-1);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}