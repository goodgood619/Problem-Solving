#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	int cnt = 1;
	int cnt2 = n - 1;
	for (int i = 1; i <=n - 1; i++){
		string s;
		int rest = n - i;
		for (; rest > 0;rest--){
			printf(" ");
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			s.push_back('*');
		}
		cout << s << endl;
	}
	for (int i = 1; i <= 2 * n - 1;i++){
		printf("*");
	}
	printf("\n");
	for (int i = n-1; i>=1; i--){
		string s;
		int rest = n-i;
		for (; rest > 0; rest--) {
			printf(" ");
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			s.push_back('*');
		}
		cout << s << endl;
	}
	return 0;
}