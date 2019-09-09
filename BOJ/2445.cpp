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
	for (int i = 1; i <= 2 * n - 1; i++){
		string s;
		int rest = 0;
		int rest2 = 0;
		if (i <= n) {
			rest = n - i;
			rest2 = i;
		}
		else {
			rest2 = 2 * n - i;
			rest = n - rest2;
		}
		for (int j = 1; j <= n; j++){
			if (rest2 != 0) {
				s.push_back('*');
				rest2--;
			}
			else {
				s.push_back(' ');
			}
		}
		string temp = s;
		reverse(temp.begin(), temp.end());
		cout << s << temp << endl;

	}
	return 0;
}