#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int length = s.size();
		int origin = 0;
		int rever = 0;
		for (int i = 0; i < length; i++){
			origin += (s[i] - '0')*pow(10, length - i - 1);
		}
		for (int i = length-1; i >= 0; i--) {
			rever += (s[i] - '0')*pow(10, i);
		}
		origin += rever;
		string temp;
		while (origin > 0) {
			temp.push_back(origin % 10 + '0');
			origin /= 10;
		}
		string temp2 = temp;
		reverse(temp.begin(), temp.end());
		if (temp == temp2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}