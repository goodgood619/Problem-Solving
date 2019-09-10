#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
string a, b;
char c[15];
char d[15];
int main(){
	scanf("%s%s", c, d);
	if (!strcmp(c, d)) printf("1\n");
	else printf("0\n");
	return 0;
}