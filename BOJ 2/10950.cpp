#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
	string s;
	int t;
	scanf("%d", &t);
	int a, b;
	while (t--){
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}