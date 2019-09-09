#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int n,Max;
int arr[10];
int ans[10];
bool visited[10];
void go(int index,int cnt) {
	if (cnt==n){
		int sum = 0;
		for (int i = 1; i < n; i++) {
			sum += abs(ans[i] - ans[i + 1]);
		}
		Max = max(sum, Max);
		return;
	}
	if (index > n) return;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]){
			visited[i] = true;
			ans[index] = arr[i];
			go(index + 1,cnt+1);
			ans[index] = 0;
			visited[i] = false;
		}
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { scanf("%d", &arr[i]);}
	go(1,0);
	printf("%d\n", Max);
	return 0;
}