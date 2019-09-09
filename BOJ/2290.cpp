
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
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int number[11][5][3] = { 
	{{0,1,0},{1,0,1},{0,0,0},{1,0,1},{0,1,0}}, //0
{{0,0,0},{0,0,1},{0,0,0},{0,0,1},{0,0,0}}, //1
{{0,1,0},{0,0,1},{0,1,0},{1,0,0},{0,1,0}}, //2
{{0,1,0},{0,0,1},{0,1,0},{0,0,1},{0,1,0}},//3
{{0,0,0},{1,0,1},{0,1,0},{0,0,1},{0,0,0}}, //4
{{0,1,0},{1,0,0},{0,1,0},{0,0,1},{0,1,0}},//5
{{0,1,0},{1,0,0},{0,1,0},{1,0,1},{0,1,0}}, //6
{{0,1,0},{0,0,1},{0,0,0},{0,0,1},{0,0,0}},//7
{{0,1,0},{1,0,1},{0,1,0},{1,0,1},{0,1,0}}, //8
{{0,1,0},{1,0,1},{0,1,0},{0,0,1},{0,1,0}}//9
};
int main() {
	setbuf(stdout, NULL);
	string s;
	int n;
	cin >> n >> s;
	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0) { //'-'
			for (int j = 0; j < s.size(); j++) {
				int num = s[j] - '0';
				printf(" ");
				for (int k = 0; k < n; k++) {
					number[num][i][1] == 1 ? printf("-") : printf(" ");
				}
				printf(" ");
				if (j != s.size() - 1) printf(" ");
			}
			printf("\n");
		}
		else { //'|'
			for (int p = 0; p < n; p++) {
				for (int j = 0; j < s.size(); j++) {
					int num = s[j] - '0';
					number[num][i][0] == 1 ? printf("|") : printf(" ");
					for (int k = 0; k < n; k++) printf(" "); //중간에 s번 공백
					number[num][i][2] == 1 ? printf("|") : printf(" ");
					printf(" ");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
