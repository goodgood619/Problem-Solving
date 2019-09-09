#include <cstdio>
#include <algorithm>
using namespace std;
int rule[105];
int jeong[105];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	int ruleti = 0;
	int jeongti = 0;
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		for (int j = ruleti; j <=ruleti+first; j++) {
			rule[j] = second;
		}
		ruleti += first;
	}
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first,&second);
		for (int j = jeongti; j <= jeongti + first; j++) {
			jeong[j] = second;
		}
		jeongti += first;
	}
	int Max = 0;
	for (int i = 0; i <= 100; i++) {
		if (rule[i] >= jeong[i]) continue;
		else Max = max(jeong[i] - rule[i], Max);
	}
	printf("%d\n", Max);
	return 0;
}
