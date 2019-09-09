#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
	int a, b;
	int cnt = 1;
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d + %d = %d\n",cnt,a,b, a + b);
		cnt++;
	}
	return 0;
}