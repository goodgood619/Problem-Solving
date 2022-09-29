#include <cstdio>
#include <vector>
#include <string>
using namespace std;
vector<string> splitSpace(string &s) {
	vector<string> v;
	string temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			v.push_back(temp);
			temp.clear();
		}
		else {
			temp.push_back(s[i]);
		}
	}
	
	v.push_back(temp); // 맨 마지막 
	return v;
}
