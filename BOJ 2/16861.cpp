#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = n;; i++) {
		string s = to_string(i);
		int a = 0;
		for (int j = 0; j < s.size(); j++) {
			a += (s[j] - '0');
		}
		if (i %a == 0) {
			printf("%d\n", i);
			return 0;
		}
		
	}
	return 0;
}