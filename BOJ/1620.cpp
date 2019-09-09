#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
map <string, int> m;
int a, b;
string nn[100003];
int main(){
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= a; i++) {
		char name[30] = { '\0', };
		scanf("%s", name);
		m.insert({ name,i });
		nn[i]=name;
	}
	for (int i = 1; i <= b; i++) {
		char what[30] = { '\0', };
		scanf("%s", what);
		if (what[0] >= 'A' && what[0] <= 'Z' || what[0] >= 'a' && what[0] <= 'z') {
			printf("%d\n", m[what]);
		}
		else {
			int length = strlen(what);
			int num = 0;
			for (int j= 0; j< length;j++) {
				num += (what[j]-'0')*pow(10, length - j - 1);
			}
			printf("%s\n", nn[num].c_str());
		}
	}
	return 0;
}