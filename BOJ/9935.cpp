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
#include <stack>
using namespace std;
typedef long long ll;
#define mod 1000000009
#define lim 1000000000
typedef pair < int, int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
string s, bomb;
char Stack[1000005];
int main(void) {
	cin >> s >> bomb;
	int index = 0;
	for (int i = 0; i < s.size(); i++) {
		Stack[index++] = s[i];
		if (s[i] == bomb[bomb.size()-1]) {
			int check = 0;
			for (int j = index - 1,s=bomb.size()-1;s>=0; s--,j--) {
				if (Stack[j] == bomb[s]) {
					continue;
				}
				else {
					check = 1;
					break;
				}
			}
			if (!check) index -= bomb.size();
		}
	}
	if (index == 0) printf("FRULA\n");
	else {
		for (int i = 0; i < index; i++) {
			printf("%c", Stack[i]);
		}
	}
	return 0;
}