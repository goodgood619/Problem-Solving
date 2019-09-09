#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string check;
string s;
char c[15] = { 'C','A','M','B','R','I','G','D','E' };
int main(){
	cin >> s;
	string check;
	int length = strlen(c);
	for (int i = 0; i < length; i++) {
		check.push_back(c[i]);
	}
	int leng = s.size();	
	for (int i = 0; i < leng; i++) {
		char here = s[i];
		for (int j = 0; j < check.size(); j++) {
			char next = check[j];
			if (here == next){
				s.erase(s.begin() + i);
				i--;
				break;
			}
		}
	}
	leng = s.size();
	for (int i = 0; i < leng; i++) {
		 cout << s[i];
	}
	return 0;
}