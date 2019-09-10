#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
bool visited[2000];
char s[103];
int main(){
	scanf("%s", s);
	int first = s[0] - '0';
	int length = strlen(s);
	visited[first*length] = true;
	first = first*length;
	bool check = false;
	while (1){
		int cnt = 0;
		while (first > 0) {
			first /= 10;
			cnt++;
		}
		if (visited[first*cnt]) {
			check = true;
			break;
		}
		visited[first*cnt] = true;
		first = first*cnt;
	}
	if (check) printf("FA\n");
	else printf("NFA");
	return 0;
}