#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string cipher, key;
int main(){
	cin >> cipher;
	cin >> key;
	for (int i = 0; i < cipher.size(); i++) {
		char c = (cipher[i] -(key[i]-'A'));
		if (c <'A') {
			c = c +26;
		}
		printf("%c", c);
		key.push_back(c);
	}
	return 0;
}