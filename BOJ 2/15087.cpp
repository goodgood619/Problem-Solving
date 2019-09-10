#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
string s;
string a;
string b;
string at;
string bt;
// A:0 ~ Z:25
int main(){
	cin >> s;
	a=s.substr(0,s.size() / 2);
	b = s.substr(s.size() / 2 , s.size());
	int asum = 0;
	int bsum = 0;
	for (int i = 0; i < a.size(); i++) {
		asum += a[i] - 65;
	}
	for (int i = 0; i < b.size(); i++) {
		bsum += b[i] - 65;
	}

	for (int i = 0; i < a.size(); i++) {
		a[i] = (a[i]-'A' + asum) % 26+'A';
		b[i] = (b[i]-'A' + bsum) % 26+'A';
	}
	for (int i = 0; i < a.size(); i++) {
		printf("%c",(a[i]-'A'+ b[i]- 'A') % 26 + 'A');
	}

	return 0;
}