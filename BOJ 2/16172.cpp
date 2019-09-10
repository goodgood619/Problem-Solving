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
using namespace std;
typedef long long ll;
int t;
vector<int> arr;
int n, m;
string team[105];
typedef pair<string, int> PP;
typedef pair<string, string> P;
map<string, int> mm;
map<int, string> mm2;
PP teamnumber[10005];
int main(){
	string s;
	cin >> s;
	string temp;
	cin >> temp;
	int length = s.size();
	int ptr = 0;
	bool no = false;
	bool check = false;
	for (int i = 0; i < length; i++) {
		if (s[i] == temp[ptr]){
			ptr++;
			continue;
		}
	}
	if (ptr != temp.size()) {
		printf("0\n");
		return 0;
	}
	ptr = temp.size()-1;
	for (int i = length-1; i>=0; i--){
		if (ptr<0) break;
		char c = s[i];
		int num = c - '0';
		if (num >= 0 && num <= 9) continue;
		else{
			if (c == temp[ptr]){
				ptr--;
				check = true;
				continue;
			}
			else{
				if (check){
					no = true;
					break;
				}
				continue;
			}
		}
	}

	if (no) printf("0\n");
	else printf("1\n");
	return 0;
}