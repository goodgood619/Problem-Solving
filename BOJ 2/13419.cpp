#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cstring>
using namespace std;
int t;
bool avisited[30];
bool bvisited[30];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(avisited, false, sizeof(avisited));
		memset(bvisited, false, sizeof(bvisited));
		bool check1 = false;
		bool check2 = false;
		char s[30] = { '\0', };
		char a[30] = { '\0', };
		char b[30] = {'\0',};
		scanf("%s", s);
		int length = strlen(s);
		int apo = 0;
		int bpo = 1;
		int ak = 0;
		int bk = 0;
		if (length >= 2) {
			while (1) {
				if (!avisited[s[apo] - 65]) {
					avisited[s[apo] - 65] = true;
					a[ak++] = s[apo];
				}
				else check1 = true;
				apo = (apo + 2) % length;
				if (!bvisited[s[bpo] - 65]) {
					bvisited[s[bpo] - 65] = true;
					b[bk++] = s[bpo];
				}
				else check2 = true;
				bpo = (bpo + 2) % length;
				if (check1 == true && check2 == true) break;
			}
			printf("%s\n", a);
			printf("%s\n", b);
		}
		else {
			printf("%s\n", s);
			printf("%s\n", s);
		}
	}
	return 0;
}