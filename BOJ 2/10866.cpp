#include <cstdio>
#include <deque>
#include <string.h>
using namespace std;
deque<int> dq;
int n;
int main(){
	scanf("%d", &n);
	while (n--) {
		char s[20] = { '\0', };
		scanf("%s", s);
		if (!strcmp(s, "push_back")) {
			int d;
			scanf("%d", &d);
			dq.push_back(d);
		}
		else if (!strcmp(s, "push_front")) {
			int d;
			scanf("%d", &d);
			dq.push_front(d);
		}
		else if (!strcmp(s, "front")) {
			if (dq.empty()) printf("-1\n");
			else printf("%d\n", dq.front());
		}
		else if (!strcmp(s, "back")) {
			if (dq.empty()) printf("-1\n");
			else printf("%d\n", dq.back());
		}
		else if (!strcmp(s, "size")){
			if(!dq.empty()) printf("%d\n", dq.size());
			else printf("0\n");
		}
		else if (!strcmp(s, "empty")) {
			if (dq.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(s, "pop_front")) {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (!strcmp(s, "pop_back")) {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
	}
	return 0;
}