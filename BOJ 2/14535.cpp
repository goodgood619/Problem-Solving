#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef pair<int, pair<int, int>> P;
int n;
int ans[13];
string s[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
void go(){
	int start = 1;
	while (start != 13) {
		cout << s[start];
		printf(":");
		while (ans[start] > 0) {
			printf("*");
			ans[start]--;
		}
		printf("\n");
		start++;
	}
}
int main(){
	int Case = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(ans, 0, sizeof(ans));
		for (int i = 1; i <= n; i++) {
			int day, month, year;
			scanf("%d%d%d", &day, &month, &year);
			ans[month]++;
		}
		printf("Case #%d:\n",Case);
		Case++;
		go();
	}
	return 0;
}