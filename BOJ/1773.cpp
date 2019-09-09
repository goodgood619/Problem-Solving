#include <stdio.h>
#include <algorithm>
using namespace std;
int fire[101];
int n,c,cnt;
bool visited[2000001];
int main(){
	scanf("%d%d", &n, &c);
	for (int i = 1; i <= n; i++) {scanf("%d", &fire[i]);}
	for (int i = 1; i <= n; i++) {
		for (int j = fire[i]; j <= c; j+=fire[i]) {
			if (!visited[j]){
				visited[j] = true;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}