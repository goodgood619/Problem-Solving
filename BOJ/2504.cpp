#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
char st[50];
int value[50];
int main(){
	char s[35] = { '\0', };
	scanf("%s", s);
	int length = strlen(s);
	int top = 0;
	for (int i = 0; i < length; i++) {
		if (s[i] == '(' || s[i] == '[') {
			st[++top]=(s[i]);
			value[top] = 0;
		}
		else {
			if (top==0) {
				printf("0\n");
				return 0;
			}
			else {
				if (st[top] == '(' && s[i] == ']') {
					printf("0\n");
					return 0;
				}
				else if (st[top] == '[' && s[i] == ')') {
					printf("0\n");
					return 0;
				}
				else if (s[i] == ')') {
					top--;
					if (value[top+1] == 0) {
						value[top]+=2;
					}
					else {
						int newpush = value[top + 1] * 2;
						value[top] += newpush;
					}
				}
				else if (s[i] == ']') {
					top--;
					if (value[top+1] == 0) {
						value[top]+=3;
					}
					else {
						int newpush = value[top+1] * 3;
						value[top] += newpush;
					}
				}
			}
		}
	}
	printf("%d\n", value[0]);
	return 0;
}