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
int j, a;
int uniform[1000005];
bool visited[1000005];
int main() {
	scanf("%d%d", &j, &a);
	for (int i = 1; i <= j; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'S') uniform[i] = 0;
		else if (c == 'M') uniform[i] = 1;
		else uniform[i] = 2;
	}
	int cnt = 0;
	for (int i = 1; i <= a; i++) {
		char c;
		int num;
		scanf(" %c%d", &c, &num);
		if (c == 'S') {
			if (uniform[num] >= 0 && !visited[num]) {
				visited[num] = true;
				cnt++;
			}
		}
		else if (c == 'M') {
			if (uniform[num] >= 1 && !visited[num]) {
				visited[num] = true;
				cnt++;
			}
		}
		else {
			if (uniform[num] >= 2 && !visited[num]) {
				visited[num] = true;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}