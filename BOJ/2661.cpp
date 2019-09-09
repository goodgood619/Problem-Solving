#include <cstdio>
#include <algorithm>
using namespace std;
char s[83];
int arr[81];
bool visited[81];
int n;
bool ok;
void go(int index, int depth){
	if (ok) return;
	for (int i = 1; i <= index / 2; i++) {
		if (equal(arr + index - i, arr + index, arr + index - i - i)) return;
	}
	if (index > n + 1) return;
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d", arr[i]);
		}
		ok = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (!visited[index]) {
			visited[index] = true;
			arr[index] = i;
			go(index + 1, depth+1);
			visited[index] = false;
			arr[index] = 0;
		}
	}
}
int main(){
	scanf("%d", &n);
	go(1, 0);
	return 0;
}