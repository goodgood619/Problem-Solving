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
using namespace std;
typedef long long ll;
int a,b;
#define mod 26
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		string s;
		char c[1000005] = { '\0', };
		scanf("%s", c);
		s = c;
		int length = s.size();
		for (int i = 0; i < length; i++) {
			int temp = ((a*(s[i] - 'A')) + b) % mod;
			printf("%c", temp + 'A');
		}
		printf("\n");
	}	
	return 0;
}