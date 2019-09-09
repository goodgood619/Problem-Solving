#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int alpha[30];
int main() {
	while (1) {
		char s[205] = { '\0', };
		scanf(" %[^\n]s", s);
		memset(alpha, 0, sizeof(alpha));
		int cnt = 0;
		if (s[0] == '*') break;
		else {
			int length = strlen(s);
			for (int i = 0; i < length; i++) {
				if (s[i] == ' ') continue;
				else {
					if (!alpha[s[i] - 97]) {
						alpha[s[i] - 97] = 1;
						cnt++;
					}
					else continue;
				}
			}
			if (cnt == 26) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}