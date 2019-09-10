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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n;	
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[35] = { '\0', };
		scanf("%s", s);
		int Size = strlen(s);
		if (s[Size - 1] == 'a') s[Size] = 's';
		else if (s[Size - 1] == 'i' || s[Size - 1] == 'y') {
			if (s[Size - 1] == 'i') {
				s[Size] = 'o', s[Size + 1] = 's';
			}
			else {
				s[Size-1]='i',s[Size] = 'o', s[Size + 1] = 's';
			}
		}
		else if(s[Size-1]=='l') s[Size] = 'e', s[Size + 1] = 's';
		else if (s[Size - 1] == 'n' || s[Size - 1] == 'e' && s[Size - 2] == 'n') {
			if (s[Size - 1] == 'n') {
				s[Size - 1] = 'a', s[Size] = 'n', s[Size + 1] = 'e',s[Size+2]='s';
			}
			else {
				s[Size - 2] = 'a', s[Size-1] = 'n', s[Size] = 'e', s[Size + 1] = 's';
			}
		}
		else if (s[Size - 1] == 'o') s[Size] = 's';
		else if (s[Size - 1] == 'r') s[Size] = 'e', s[Size + 1] = 's';
		else if (s[Size - 1] == 't') s[Size] = 'a', s[Size + 1] = 's';
		else if (s[Size - 1] == 'u') s[Size] = 's';
		else if(s[Size-1]=='v') s[Size] = 'e', s[Size + 1] = 's';
		else if(s[Size-1]=='w') s[Size] = 'a', s[Size + 1] = 's';
		else {
			s[Size] = 'u', s[Size + 1] = 's';
		}
		printf("%s\n", s);
	}
	return 0;
}