#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int t;
int state[10][2] = { {8,1},{2,9},{3,9},{3,4},{8,5},{6,5},{3,7},{8,1},{9,7},{9,9}};
bool go(char *c){
	int start = 0;
	int length = strlen(c);
	for (int i = 0; i < length; i++) {
		int cur = c[i] - '0';
		start = state[start][cur];
	}
	if (start == 4 || start == 5 || start == 7) return true;
	else return false;
}
int main(){
	scanf("%d", &t);
	while (t--) {
		char c[205] = { '\0', };
		scanf("%s", c);
		bool chk=go(c);
		if (chk) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}