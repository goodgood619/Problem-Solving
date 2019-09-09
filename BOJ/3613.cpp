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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int main() {
	setbuf(stdout, NULL);
	string s;
	cin >> s;
	int small = 0,big=0,cnt=0,no=0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') small++;
		if (s[i] >= 'A' && s[i] <= 'Z') big++;
		if (s[i] == '_') cnt++;
		if (i < s.size() - 1 && s[i] == '_' && s[i + 1] == '_')  no = 1;
		if (i < s.size() - 1 && s[i] == '_' && s[i + 1] >= 'A' && s[i + 1] <= 'Z') no = 1;
		if (s[0] >= 'A' && s[0] <= 'Z') no = 1;
	}
	if (small == s.size()) printf("%s", s.c_str());
	else if (big == s.size()  || no || s[0]=='_' || s[s.size()-1]=='_') printf("Error!\n"); //전부대문자,_도 있고, 대문자도 있을때,_연속
	else {
		if (big > 0) { //java->c++
			string temp;
			temp.push_back(s[0]);
			int no1 = 0;
			for (int i = 1; i < s.size(); i++) {
				if (s[i] >= 'A' && s[i] <= 'Z') {
					temp.push_back('_');
					temp.push_back(s[i] + 32);
				}
				else if(s[i]>='a' && s[i]<='z')temp.push_back(s[i]);
				else no1 = 1;
			}
			no1==1?printf("Error!\n"): printf("%s", temp.c_str());
		}
		else { //c++->java
			string temp;
			int no2 = 0;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '_') {
					temp.push_back(s[i + 1] - 32);
					i++;
				}
				else if(s[i]>='a' &&s[i]<='z')temp.push_back(s[i]);
				else no2 = 1;
			}
			no2==1?printf("Error!\n"):printf("%s\n", temp.c_str());
		}
	}
	return 0;
}