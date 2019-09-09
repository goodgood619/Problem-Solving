#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[1005];
bool visited[1005];
int n, k,cnt;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++){
		int diff = arr[i] + k;
		int temp = 1;
		for (int j = i + 1; j <= n; j++) {
			if (arr[j] > diff) break;
			else {
				temp++;
			}
		}
		cnt = max(temp, cnt);
	}
	printf("%d\n", cnt);
	return 0;
}