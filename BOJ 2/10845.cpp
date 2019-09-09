#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
using namespace std;
int arr[10005];
int n,ptr=-1,p;
void push(int num) {
	arr[++ptr] = num;
}
int pop() {
	if (ptr < 0 || p>ptr) return -1;
	else {
		return arr[p++];
	}
}
int front() {
	if (ptr < 0 || p > ptr) return -1;
	else return arr[p];
}
int back() {
	if (ptr < 0 || p > ptr) return -1;
	else return arr[ptr];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char s[15] = { '\0', };
		scanf("%s", s);
		if (!strcmp(s, "push")) {
			int num;
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(s, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(s, "size")) {
			printf("%d\n", ptr-p+1);
		}
		else if (!strcmp(s, "empty")) {
			if (p>ptr) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(s, "front")) {
			printf("%d\n", front());
		}
		else if (!strcmp(s, "back")) {
			printf("%d\n", back());
		}
	}
	return 0;
}