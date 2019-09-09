#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
int n;
string s[51];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { cin >> s[i];}
	int length = s[0].size();
	int cnt = 0;
	for (int i = 0; i < length; i++){
		cnt = 0;
		char c=s[0][i];
		for (int j = 1; j < n; j++) {
			if (c == s[j][i]) cnt++;
		}
		if (cnt == n - 1) printf("%c", c);
		else printf("?");
	}
	return 0;
}