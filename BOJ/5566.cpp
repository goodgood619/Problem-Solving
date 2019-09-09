#include <cstdio>
#include <algorithm>
using namespace std;
int n, m,cnt;
int arr[1001];
int dice[1001];
int main(){
	scanf("%d%d", &n,&m);
	int start = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &dice[i]);
	}
	for (int i = 1; i <= m; i++){
		if (start>=n) break;
		int go = dice[i];
		start += go;
		cnt++;
		if (arr[start] == 0) continue;
		else if (arr[start] > 0) {
			start += arr[start];
			continue;
		}
		else if (arr[start] < 0) {
			start += arr[start];
			continue;
		}
	}
	printf("%d\n", cnt);
	return 0;
}