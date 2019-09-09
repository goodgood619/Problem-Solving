#include <stdio.h>
#include <algorithm>
using namespace std;
char num[15];
int n,p,cnt;
int k = 2;
bool visited[15];
char temp[15];
char ans[1025][11];
bool ok;
void go(int index, int depth){
	if (ok) return;
	if (index > k) return;
	if (depth == k) {
		bool check = false;
		for (int i = 0; i < depth-1; i++) {
			if (temp[i] <temp[i + 1]) check = true;
			else continue;
		}
		if (check) return;
		else {
			for (int i = 0; i < depth; i++) {
				ans[p][i] = temp[i];
			}
			p++;
			cnt++;
			if (cnt == n) { printf("%s\n", ans[p - 1]); ok = true; return; }
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp[index] = i + '0';
			go(index + 1, depth + 1);
			visited[i] = false;
			temp[index] = ' ';
		}
	}
}
int main() {
	scanf("%d", &n);
	if (n < 10) printf("%d\n", n);
	else if (n >= 1023) printf("-1\n");
	else {
		cnt = 9;
		for (int i = 2; i <= 10; i++) {
			go(0, 0);
			k++;
		}
	}
	return 0;
}