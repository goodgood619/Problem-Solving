#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, l;
int arr[1001];
int main() {
	scanf("%d%d%d", &n, &m, &l);
	int cnt = 0;
	int start = 1;
	while (1) {
		arr[start]++;
		if (arr[start] == m) break;
		if (arr[start] % 2 == 0) {
			start -= l;
			if (start == 0) start = n;
			else if (start < 0) start = n + start;
			cnt++;
		}
		else if (arr[start] % 2 == 1) {
			start += l;
			if (start%n == 0) start = n;
			else start=start%n;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

