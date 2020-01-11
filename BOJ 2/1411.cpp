#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string* a = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int check1[27] = { 0,}, check2[27] = {0,};
			int temp = 0;
			for (int k = 0; k < a[i].size(); k++) {
				int c1 = a[i][k] - 'a'+1, c2 = a[j][k] - 'a'+1;
				if (!check1[c1] && !check2[c2]) {
					check1[c1] = c2, check2[c2] = c1;
				}
				else if (check1[c1] != c2) {
					temp = 1;
					break;
				}
			}
			if (!temp && a[i].size() && a[j].size()) ans++;
		}
	}
	printf("%d\n", ans);
	delete[] a;
	return 0;
}