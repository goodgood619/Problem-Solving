#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
int l, c;
int check[17];
char arr[17];
void search(int cnt, int mo, int ja, string ans,int index) {
	if (cnt == l) {
		if (mo >= 1 && ja >= 2) {
			cout << ans << endl;
			return;
		}
	}
	for (int i = index; i < c; i++) {
		if (!check[i]) {
			check[i] = 1;
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
				search(cnt + 1, mo + 1, ja, ans + arr[i],i+1);
			else
				search(cnt + 1, mo, ja + 1, ans + arr[i],i+1);
			check[i] = 0;
		}
	}
	return;
}

int main() {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++) {
		scanf(" %c", &arr[i]);
	}
	sort(arr, arr + c);
	search(0, 0, 0, "",0);
}