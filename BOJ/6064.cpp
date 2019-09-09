#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
using namespace std;
int a,b,c,d;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d%d", &a, &b,&c,&d);
		bool check = false;
		int g = gcd(a, b);
		int Max = a / g * b / g * g;
		int yptr = 0;
		int xptr = 0;
		int ans = 0;
		while (1){
			int xtemp = a * xptr;
			int ytemp=b*yptr + d - c;
			if (ytemp%a==0){
				ans = ytemp;
				check = true;
				break;
			}
			else if(ytemp<=Max)yptr++;
			else break;
		}
		if (!check) printf("-1\n");
		else {
			printf("%d\n", ans+c);
		}
	}
	return 0;
}