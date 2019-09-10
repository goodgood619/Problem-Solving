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
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int cnt[27];
int main() {
	char c[255] = { '\0', };
	scanf("%[^\n]s", c);
	int length = strlen(c);
	for (int i = 0; i < length; i++) {
		if (c[i] >= 'A' && c[i] <= 'Z') cnt[c[i] - 'A']++;
		else if (c[i] >= 'a' && c[i] <= 'z') cnt[c[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%c | ", i + 65);
		for (int j = 0; j < cnt[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}